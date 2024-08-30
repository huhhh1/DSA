#include <iostream>
using namespace std;
class queue
{
private:
    struct ArrayQueue
    {
        int rear, front;
        int capacity;
        int *array;
    };
    struct ArrayQueue *n;

public:
    queue(int cap)
    {
        n = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));
        n->capacity = cap;
        n->front = -1;
        n->rear = -1;
        n->array = (int *)malloc(sizeof(int) * n->capacity);
    };

    bool isEmpty()
    {
        return n->front == -1;
    };
    bool isFull()
    {
        return ((n->rear + 1) % n->capacity == n->front);
    };
    int size()
    {
        return ((n->capacity - n->front + n->rear + 1) % (n->capacity));
    };
    void enQueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is OverFlaw" << endl;
        }
        else
        {
            n->rear = (n->rear + 1) % n->capacity;
            n->array[n->rear] = item;
            if (n->front == -1)
            {
                n->front = n->rear;
            }
        }
    };
    int deQueue()
    {
        int data = -1;
        if (isEmpty())
        {
            cout << "Queue is UnderFlaw" << endl;
            return -1;
        }
        else
        {
            data = n->array[n->front];
            if (n->front == n->rear)
            {
                n->front = n->rear = -1;
            }
            else
            {
                n->front = (n->front + 1) % n->capacity;

            }
            return data;
        }
    };
    void view()
    {
        int i = n->front;
        while (i != n->rear)
        {
            cout << n->array[i] << endl;
            i--;
        }
    }
    void deleteQueue()
    {
        if (n)
            if (n->array)
                free(n->array);
        free(n);
    };
};

int main()
{

    queue arrayQueue(4);
    arrayQueue.enQueue(1);
    arrayQueue.enQueue(2);
    arrayQueue.enQueue(3);
    arrayQueue.view();
    int size1 = arrayQueue.size();
    cout << "Size of Queue" << size1 << endl;
    cout << "Befor del" << endl;
    int del = arrayQueue.deQueue();
    cout << "Deleted Item" << del << endl;
    cout << "after del" << endl;
    arrayQueue.view();
    int size2 = arrayQueue.size();
    cout << "Size of Queue" << size2 << endl;
}



