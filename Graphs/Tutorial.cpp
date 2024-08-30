#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int vertexNo;
    struct ListNode *link;
};
struct Graph
{
    int vertex;
    int edges;
    struct ListNode *Adjacency;
};
// Returning A Directed Graph ;
struct Graph *Create_Graph()
{
    struct Graph *g;
    g = (struct Graph *)malloc(sizeof(struct Graph));
    cout << " Enter the number of the vertex and Edges :- ";
    cin >> g->vertex >> g->edges;
    cout << endl;
    g->Adjacency = (struct ListNode *)malloc(g->vertex * sizeof(struct ListNode));
    for (int i = 0; i < g->vertex; i++)
    {
        g->Adjacency[i].vertexNo = i;
        g->Adjacency[i].link = g->Adjacency + i;
    }
    int x, y;
    struct ListNode *temp, *help;
    for (int i = 0; i < g->edges; i++)
    {
        cout << "Enter the source & Destination : ";
        cin >> x >> y;
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->vertexNo = y;
        temp->link = (g->Adjacency + x);
        help = (g->Adjacency + x);
        while (help->link != (g->Adjacency + x))
            ;
        help = help->link;
        help->link = temp;
    }
    return g;
};

void Graph_AdjList()
{
    int vertex, edges;
    cout << "Eneter the number of Vertex & Edges : ";
    cin >> vertex >> edges;
    // Not Weighted Graph       // based 1 Index
    cout << endl;
    vector<int> adj[vertex + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter the Source & destination : ";
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // For Directed graph
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // For Weighted Graph
    vector<pair<int, int>> adj_pair[vertex + 1];
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cout << "Write The Source & Destination & Weight : ";
        cin >> u >> v >> w;
        // for directed  graph
        adj_pair[u].push_back({v,w});
        // For Undirected Graph
        adj_pair[u].push_back({u,w});
        adj_pair[v].push_back({v,w});
    }

};

int main()
{


    return 0;
}