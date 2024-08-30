#include <iostream>
using namespace std;
struct binarytreeNode
{
    int data;
    struct binarytreeNode *left, *right;
};
// struct BinaryTree
// {
//     int data;
//     struct BinaryTree *left, *right;
// };

struct binarytreeNode *root = NULL;

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
        else if(root->data<data)
        {
            root->right = insertNode(root->right, data);
        }
        else
            cout<<"Invalid Number"<<endl;
    }
};

// void inorderTra(struct BinaryTree *root){
//     if(root==NULL)
//         return;
//     inorderTra(root->left);
//     cout<<root->data<<"\t";
//     inorderTra(root->right);
// }

// bool find(struct BinaryTree *root, int data)
// {
//     if (root == NULL)
//         return false;
//     else
//     {
//         if (root->data > data)
//             return find(root->left, data);
//         else if (root->data < data)
//             return find(root->right, data);
//         else
//             return true;
//     }
// }

// struct BinaryTree *inorderSuccessor(struct BinaryTree *root){
//     while (root!=NULL)
//     {
//         root = root->left;
//     }
//     return root;
// };

// struct BinaryTree *deleteNode(struct BinaryTree *root,int data){
//     if(root==NULL)
//         cout<<"What the fuck "<<endl;
//     if(root->data>data)
//         root->left = deleteNode(root->left,data);
//     else if(root->data<data)
//         root->right=deleteNode(root->right,data);
//     else{
//         struct BinaryTree *temp;
//         if(root->left&&root->right){
//             temp = inorderSuccessor(root->right);
//             root->data=temp->data;
//             root->right = deleteNode(root->right,root->data);
//         }
//         else{
//             temp = root;
//             if(root->right==NULL)
//                 root = root->left;
//             else if(root->left==NULL)
//                 root = root->right;
//         }
//         free(temp);
//         return root;
//     }

// };


struct binarytreeNode *insert(struct binarytreeNode *root, int data)
{
    struct binarytreeNode *n, *par;
    n = (struct binarytreeNode *)malloc(sizeof(struct binarytreeNode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    if (root == NULL)
        root = n;
    else
    {
        par = root;
        while (par != NULL)
        {
            if (par->data > data)
            {
                if (par->left == NULL)
                    par->left = n;
                par = par->left;
            }
            else if (par->data < data)
            {
                if (par->right == NULL)
                    par->right = n;
                par = par->right;
            }
        }
    };
}
struct binarytreeNode *find(struct binarytreeNode *root, int data){
    
    if (root == NULL)
        return NULL;
    else
    {
        if (root->data > data)
            return find(root->left, data);
        else if (root->data < data)
            return find(root->right, data);
        return (root);
    }
}
// struct binarytreeNode *deleteNode(struct binarytreeNode *root, int data)
// {
//     if (root == NULL)
//         return NULL;
//     else
//     {
//         if (root->data > data)
//         {
//             root->left = deleteNode(root->left, data);
//         }
//         else if (root->data < data)
//         {
//             root->right = deleteNode(root->right, data);
//         }
//         else
//         {
//             struct binarytreeNode *temp1;
//             if (root->left && root->right)
//             {
//                 temp1 = FindMax(root->left);
//                 root->data = temp1->data;
//                 root->left = deleteNode(root->left, root->data);
//             }
//             else
//             {
//                 temp1 = root;
//                 if (root->left == NULL)
//                     root = root->right;
//                 else if (root->right == NULL)
//                     root=root->left;
//                 free(temp1);
//             }
//         }
//         return root;
//     }
// };
int main()
{
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,3);
    return 0;
}