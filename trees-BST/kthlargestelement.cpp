#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data1)
    {
        data = data1;
        left = right = nullptr;
    }
};
int result=0,count=0;
void inorder(node* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->right,k);
    ::count++;
    if(::count==k)
    {
        ::result=root->data;
    }
    inorder(root->left,k);
}
int kthlargest(node* root,int k)
{
    inorder(root,k);
    return result;
}
int main()
{
    node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    int k=3;
    cout<<kthlargest(root,k);
    return 0;
}

