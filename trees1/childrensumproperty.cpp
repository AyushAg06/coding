#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int data1)
        {
            data=data1;
            left=right=nullptr;
        }
};
void changetree(node* root)
{
    if(root==NULL)
    {
        return;
    }
    int child=0;
    if(root->left!=NULL)
    {
        child+=root->left->data;
    }
    if(root->right!=NULL)
    {
        child+=root->right->data;
    }
    if(child>root->data)
    {
        root->data=child;
    }
    else
    {
        if(root->left!=NULL)
        {
            root->left->data=child;
        }
        if(root->right!=NULL)
        {
            root->right->data=child;
        }
    }
    changetree(root->left);
    changetree(root->right);
    int total=0;
    if(root->left!=NULL)
    {
        total+=root->left->data;
    }
    if(root->right!=NULL)
    {
        total+=root->right->data;
    }
    if(root->left!=NULL || root->right!=NULL)
    {
        root->data=total;
    }
}
void inorderTraversal(node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    changetree(root);
    inorderTraversal(root);
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6