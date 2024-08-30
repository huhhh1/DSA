// "CREATE AND INSERT NODE IN 'LINKED LIST'"
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node *link;
};
struct node *head;
struct node *createNODE(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->info = data;
    n->link = NULL;
    return n;
};
void insertNODE(int data)
{
    struct node *temp, *t;
    temp = createNODE(data);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        t = head;
        while (t->link != NULL)
        {
            t = t->link;
        }
        t->link = temp;
    }
};
void deleteNODE(int del)
{
    struct node *temp, *f, *n;
    if (head != NULL)
    {
        int d = 0;
        temp = head;
        while (d != del && temp->link != NULL)
        {
            n = temp;
            temp = temp->link;
            d++;
        }
        f = temp->link;
        n->link = f;
        free(temp);
    }
    else
    {
        cout << "Error -> Ther is no Node list" << endl;
    }
};
void view(){
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->info << "->";
        temp = temp->link;
    }
    cout << endl;
};
void help()
{
    cout << "For 'CREATE_NODE_IN_LIST' node in list :- "
         << "'createNODE'\n";
    cout << "For 'VIEW_LIST' node in list :- "
         << "'view'\n";
    cout << "For 'DELETE_FIRST_NODE' node in list :- "
         << "'deleteNODE'\n";
    cout << "For 'INSERT_NODE_IN_LIST' node in list :- "
         << "'insertNODE'\n";
};
void reverse_list(node *prev, node *next){
    if (!next->link)
    {
        head = next;
        next->link = prev;
        return;
    }
    reverse_list(next, next->link);
    next->link = prev;
    return;
}
struct node *Middle_Node(struct node *root){
    struct node *sl = root, *ft = root;
    while (ft->link && ft)
    {
        ft = ft->link->link;
        sl = sl->link;
    }
    return sl;
}
bool Is_cycle(struct node *root){

    struct node *temp, *middle = Middle_Node(root);
    temp = middle;
    while (temp)
    {
        if (temp->link == middle)
            return false;
        temp = temp->link;
    }
    return true;
}
int main()
{
    struct node *left = head, *right = NULL, *nxt,*prev = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertNODE(x);
    }
    int k=4;
    view();
    //  1 2 2 4 5 6 7 8 
    while (k--)
    {
        nxt = left->link;
        left->link = prev;
        prev = left;
        left = nxt;
        cout<<prev->info<<" ";
    }
    left = prev;
    right = nxt;
    prev = NULL;
    head = left;
    view();
    while (right)
    {
        nxt=right->link;
        right->link = prev;
        prev = right;
        right = nxt;
    }
    head->link = prev;
    head = left;
    view();
    return 0;
};
