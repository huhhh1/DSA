#include <bits/stdc++.h>
using namespace std;

struct BinaryTree
{
    int data;
    struct BinaryTree *left, *right;
};
struct BinaryTree *root = NULL;
struct BinaryTree *insertNode (struct BinaryTree *root, int data)
{
    if (root == NULL)
    {
        struct BinaryTree *n = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
        n->data = data;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return root;
    }
    else
    {
        if (root->data > data)
        {
            root->left = insertNode(root->left, data);
        }
        else if(root->data < data)
        {
            root->right = insertNode(root->right, data);         
        }
        return root;
    }
};
void inorderTra(struct BinaryTree *root){
    if(root==NULL)
        return;
    inorderTra(root->left);
    cout<<root->data<<"\t";
    inorderTra(root->right);
}
bool find(struct BinaryTree *root, int data)
{
    if (root == NULL)
        return false;
    else
    {
        if (root->data > data)
            return find(root->left, data);
        else if (root->data < data)
            return find(root->right, data);
        else
            return true;
    }
}
struct BinaryTree *inorderSuccessor(struct BinaryTree *root){
    while (root!=NULL)
        root = root->left;
    return root;
};
struct BinaryTree *deleteNode(struct BinaryTree *root,int data){
    if(root == NULL)
        cout<<"What the fuck "<<endl;
    if(root->data>data)
        root->left = deleteNode(root->left,data);
    else if(root->data<data)
        root->right=deleteNode(root->right,data);
    else{
        struct BinaryTree *temp;
        if(root->left&&root->right){
            temp = inorderSuccessor(root->right);
            root->data=temp->data;
            root->right = deleteNode(root->right,root->data);
        }
        else{
            temp = root;
            if(root->right==NULL)
                root = root->left;
            else if(root->left==NULL)
                root = root->right;
        }
        free(temp);
        return root;
    }

};
void rangePrint(struct BinaryTree *root,int x,int y){
    if(root==NULL)
        return;
    if(root->data>=x && root->data<=y){
        rangePrint(root->left,x,y);
        cout<<root->data<<" ";
        rangePrint(root->right,x,y);
    }
    else if(root->data>=y)
        rangePrint(root->left,x,y);
    else
        rangePrint(root->right,x,y);

};
// class Coonvert_bst_2_balanced_bst {
// private:
// void intraver(Node *root,vector<Node*>&arr){
//     if( root != NULL ){
//         intraver(root->left,arr);
//         arr.push_back(root);
//         intraver(root->right,arr);
//     }
//     return;
// }
// Node* divide(vector<Node*>&arr,int l,int r){
//     if(l>r)
//         return NULL;
//     int mid = l+(r-l)/2;
//     Node *root = arr[mid];
//     root->left = divide(arr,l,mid-1);
//     root->right = divide(arr,mid+1,r);
//     return root;
// }
// public:
// Your are required to complete this function
// function should return root of the modified BST
// Node* buildBalancedTree(Node* root){
//     vector<Node*>arr;
//     intraver(root,arr);
//     root = divide(arr,0,arr.size()-1);
//     return root;
// }
// };


int main()
{
    vector<int> v = {1,4,3,4,5,6,2};
    for (int i = 0; i < v.size(); ++i)
        root = insertNode(root, v[i]);
    inorderTra(root);
    cout<<endl;
    rangePrint(root,2,6);
    return 0;
}