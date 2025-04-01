#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 8080       
#define MAX_CLIENTS 10  
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS]; 
int log_pipe[2];

void broadcast_message(const char *message, int sender_fd) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] > 0 && client_sockets[i] != sender_fd) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_fd, int log_fd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);

        // Receive message from client
        int bytes_read = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_read <= 0) {
            printf("Client (FD %d) disconnected.\n", client_fd);
            close(client_fd);
            exit(0);
        }

        // Log the message to parent via pipe
        char log_message[BUFFER_SIZE + 50];
        snprintf(log_message, sizeof(log_message), "Client (FD %d): %s\n", client_fd, buffer);
        write(log_fd, log_message, strlen(log_message));

        // Broadcast the message to other clients
        broadcast_message(buffer, client_fd);
    }
}

void cleanup_children(int sig) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

int main() {
    int server_fd, new_socket, max_sd, activity;
    struct sockaddr_in address;
    socklen_t addr_len = sizeof(address);
    char buffer[BUFFER_SIZE];

    // Signal handling for child process cleanup
    signal(SIGCHLD, cleanup_children);

    // Initialize all client sockets to 0 (not connected)
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started. Listening on port %d...\n", PORT);

    // Create a pipe for parent-child logging communication
    if (pipe(log_pipe) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Non-blocking log pipe for parent
    fcntl(log_pipe[0], F_SETFL, O_NONBLOCK);

    fd_set readfds;

    while (1) {
        // Clear and set file descriptors
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        FD_SET(log_pipe[0], &readfds);
        max_sd = server_fd > log_pipe[0] ? server_fd : log_pipe[0];

        // Add client sockets to the set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (sd > 0) FD_SET(sd, &readfds);
            if (sd > max_sd) max_sd = sd;
        }

        // Wait for activity on one of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR)) {
            perror("select");
        }

        // Check for new connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addr_len)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New client connected: FD %d\n", new_socket);

            // Add new socket to the client sockets array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;

                    // Fork to handle the new client
                    pid_t pid = fork();
                    if (pid == 0) {
                        close(server_fd); // Child doesn't need the listening socket
                        close(log_pipe[0]); // Close read end of the pipe
                        handle_client(new_socket, log_pipe[1]);
                    }
                    break;
                }
            }
        }

        // Check for messages in the log pipe
        if (FD_ISSET(log_pipe[0], &readfds)) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_read = read(log_pipe[0], buffer, BUFFER_SIZE);
            if (bytes_read > 0) {
                printf("Log: %s", buffer); // Print log from child processes
            }
        }

        // Check for messages from clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (FD_ISSET(sd, &readfds)) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_read = read(sd, buffer, BUFFER_SIZE);
                if (bytes_read <= 0) {
                    printf("Client (FD %d) disconnected.\n", sd);
                    close(sd);
                    client_sockets[i] = 0;
                }
            }
        }
    }

    return 0;
}
