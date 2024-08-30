#include <iostream>
using namespace std;
struct stack{
    int top, capicity;
    int *array;
};
struct stack *createStack(int cap){
    struct stack *n;
    n = (struct stack *)malloc(sizeof(struct stack));
    n->top=-1;
    n->capicity=cap;
    n->array=(int*)malloc(sizeof(int)*n->capicity);
    return n;
};

struct stack *s = createStack(6);
void push(int item){
    if(s->top==s->capicity-1)
        cout<<"Stack is overflow"<<endl;
    else{
        s->top++;
        s->array[s->top]=item;
    }
}
int pop(){
    int del = 0;
    if(s->top==-1){
        cout<<"Stack is underflaw"<<endl;
        return -1;}
    else{
        del=s->array[s->top];
        s->top--;
        return del;
   }
};
int peep(){
    if(s->top!=-1){
        return s->array[s->top];
    }
    else{
        cout<<"Stack is UnderFLow"<<endl;
        return -1;
    }
};
void view(){
    int temp=0;
    int v;
    if(s->top!=-1){
    while (temp<=s->top)
    {
        cout<<(temp+1)<<"."<<s->array[temp]<<endl;
        temp++;
    }
    }
    else{
        cout<<"Stack is underFlow"<< endl;
    }
    
};
void change(int index,int item){

    if(s->top!=-1 && index<=s->top)
        s->array[index]=item;
    else{
        cout<<"Stack si UnderFlow"<<endl;
    }
};
int main(){
    int temp,del,item,index;
    while (true)
    {
        cout<<"1.Push  2. pop  3.view 4.change  5.Peep  6.exit :-  ";
        cin>>temp;
        switch (temp)
        {
        case 1:
            cout<<"Enter the item:- ";
            cin>>item;
            push(item);            
            break;
        case 2:
            cout<<"Poped Value : "<<pop()<<endl;
            break;
        case 3:
            view();
            break;
        case 4:
            cout<<"Enter the index:- ";
            cin>>index;
            cout<<"\nEnter the item:- ";
            cin>>item;
            change(index,item);
            break;
        case 5:
            cout<<"Peep Value Of stack : "<<peep()<<endl;
            break;
        case 6:
            exit(false);
            break;
        default:
            break;
        }
    }
    if(s){
        if(s->array)
            free(s->array);
        free(s);
    }
    return 0;
}


