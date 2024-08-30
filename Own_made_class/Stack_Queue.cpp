#include <iostream>
using namespace std;
class Queue
{
private:
    struct QueueArray
    {
        int front, rear, cap;
        string *array;
    };
    struct QueueArray *q;

public:
    Queue(int cap = 0)
    {
        q = (struct QueueArray *)malloc(sizeof(struct QueueArray));
        this->q->cap = cap;
        this->q->front = -1;
        this->q->rear = -1;
        this->q->array = (string *)malloc(sizeof(string) * this->q->cap);
    }
    void push(string str)
    {
        if (this->q->cap - 1 != this->q->rear)
        {
            if (this->q->front == -1)
                this->q->front++;
            this->q->rear++;
            this->q->array[this->q->rear] = str;
        }
        else
        {
            cout << "OverFlow" << endl;
        }
    };
    string pop()
    {
        int temp_rear = 0;
        string del;
        if (this->q->front != -1)
        {
            del = this->q->array[temp_rear];
            if (this->q->rear == 0)
            {
                this->q->front--;
                this->q->rear--;
            }
            else
            {
                while (temp_rear < this->q->rear)
                {
                    this->q->array[temp_rear] = this->q->array[temp_rear + 1];
                    temp_rear++;
                };
                this->q->rear--;
            }
            return del;
        }
    };
    int length()
    {
        return this->q->rear + 1;
    }
    void view()
    {
        int temp_rear = 0;
        while (temp_rear <= this->q->rear)
        {
            cout << temp_rear << " . " << this->q->array[temp_rear] << endl;
            temp_rear++;
        }
    }
    
};
class Stack

{
private:
    struct ArrayStack
    {
        int top, cap;
        char *array;
    };
    struct ArrayStack *s;

public:
    Stack(int cap = 0)
    {
        s = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
        this->s->top = -1;
        this->s->cap = cap;
        this->s->array = (char *)malloc(sizeof(char) * this->s->cap);
    };
    void push(char itme)
    {
        if (this->s->cap - 1 != this->s->top)
        {
            this->s->top++;
            this->s->array[this->s->top] = itme;
        }
        else
        {
            cout << "Stack is OverFlow" << endl;
        }
    }
    char pop()
    {
        int del;
        if (this->s->top != -1)
        {
            del = this->s->array[this->s->top];
            this->s->top--;
            return del;
        }
        else
        {
            cout << "Stack is UnderFlow" << endl;
            return -1;
        }
    }
    int length()
    {
        return this->s->top + 1;
    }
    void view()
    {
        int temp = s->top;
        while (temp>=0)
        {
            cout << this->s->array[temp];
            temp--;
        }
    }
};




