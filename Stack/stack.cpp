#include <iostream>
#include <typeinfo>
using namespace std;
struct Arraystack
{
    int Top;
    unsigned capacity;
    int *array;
};
struct Arraystack *create(int cap)
{
    struct Arraystack *n;
    n = (struct Arraystack *)malloc(sizeof(struct Arraystack));
    n->capacity = cap;
    n->Top = -1;
    n->array = (int *)malloc(sizeof(int) * n->capacity);
    return n;
}
int isFULL(struct Arraystack *stack)
{
    if (stack->Top == stack->capacity - 1)
        return 1;
    return 0;
}
int isEMPTY(struct Arraystack *stack)
{
    if (stack->Top == -1)
        return 1;
    return 0;
}
void push(struct Arraystack *stack, int item)
{
    if (!isFULL(stack))
    {
        stack->Top++;
        stack->array[stack->Top] = item;
    }
    else
    {
        cout << "Stack is Over flow" << endl;
    }
}

int pop(struct Arraystack *stack)
{
    int popitem;
    if (!isEMPTY(stack))
    {
        popitem = stack->array[stack->Top];
        stack->Top--;
        return popitem;
    }

    else
    {
        cout << "Stack is under Flow" << endl;
    }
}
int main()
{
    struct Arraystack *stack=create(5);
    int num,a=1;
    cout << "\n 1 push :" << endl;
    cout << "\n 2 pop :" << endl;
    while (true)
    {
            cout << "\n Enter Number :- ";
        cin >> num;
        switch (num)
        {
        case 1:
            int b;
            cout << "Enter the num for push :" << endl;
            cin >> b;
            push(stack, b);
            break;
        case 2:
            int item;
            item = pop(stack);
            cout<<"poped item("<<item<<")"<<endl;
            break;        
        default:
            cout<<"bitch fuvck";
            exit(false);

    }
}
    return 0;
}