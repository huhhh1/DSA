#include <iostream>
using namespace std;

struct queueArray
{
    int front, rear;
    int cap;
    int *array;
};

struct queueArray *create(int cap)
{
    struct queueArray *n;
    n = (struct queueArray *)malloc(sizeof(struct queueArray));
    n->front = -1;
    n->rear = -1;
    n->cap = cap;
    n->array = (int *)malloc(sizeof(int) * n->cap);
    return n;
};
struct queueArray *queue = create(5);

void push(int item)
{
    if (queue->front == -1)
    {
        queue->front += 1;
    };
    if (queue->rear < queue->cap-1)
    {
        queue->rear += 1;
        queue->array[queue->rear] = item;
    }
    else
    {
        cout << "Queue is Overflow" << endl;
    }
};
int pop()
{
    int del = 0;
    int temprear = queue->front;
    if (queue->front != -1)
    {
        del = queue->array[temprear];
        if (queue->rear == 0)
        {
            queue->rear--;
            queue->front--;
        }
        else
        {
            while (temprear < queue->rear)
            {
                queue->array[temprear] = queue->array[temprear + 1];
                temprear++;
            }
            queue->rear--;
        }
        return del;
    }
    else
    {
        cout << "Queue is underFlow" << endl;
        return -1;
    }
};

void view()
{
    int tempfront = queue->front;
    if (queue->front == -1)
    {
        cout << "Queue is underflow" << endl;
    }
    else
    {
        while (tempfront <= queue->rear)
        {
            cout << tempfront << " : " << queue->array[tempfront]<<endl;;
            tempfront += 1;
        }
    }
}
int main()
{
    int temp, item;
    while (true)
    {
        cout << "1.Push  2. pop  3.view  4.exit :-  ";
        cin >> temp;
        switch (temp)
        {
        case 1:
            cout << "Enter the item:- ";
            cin >> item;
            push(item);
            break;
        case 2:
            cout << "Poped Value : " << pop() << endl;
            break;
        case 3:
            view();
            break;
        case 4:
            exit(false);
            break;
        default:
            break;
        }
    }
    if (queue)
    {
        if (queue->array)
            free(queue->array);
        free(queue);
    }
    return 0;
}
