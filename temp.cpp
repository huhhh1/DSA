#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   struct Node *link;
};
struct Node *root=NULL;
void insertion(struct Node *root,int data){
   if(root==NULL){
      struct Node *n;
      n->data=data;
      n->link=NULL;
      return;
   };
   insertion(root->link,data);
   return;
}
void Reverse_nodeList(struct Node *next,struct Node *prev){
   if(!next->link){
      root=next;
      next->link=prev;
      return;
   }
      Reverse_nodeList(next,next->link);
      next->link=prev;
   return;
};
struct Node *Middle_Node(struct Node *root){
   struct Node *sl=root;
   struct Node *fs=root;
   while (fs&&fs->link)
   {
      fs=fs->link->link;
      sl=sl->link;
   }
   return sl;
};
bool Is_cycle(struct Node *root){
   struct Node *temp,*middle=Middle_Node(root);
   temp=middle;
   while (temp)
   {
      if(temp->link!=middle) return false;
      temp=temp->link;
   }
   return;
}

int main(){  
   struct Node *prev=NULL,*curr=root,*save;
   while (curr)
   {
      save = curr->link;
      curr->link=prev;
      prev=curr;
      curr=save;
   }  
   return 0;
}