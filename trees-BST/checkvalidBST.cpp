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
bool isBST(node* root, int minval, int maxval)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < minval || root->data > maxval)
    {
        return false;
    }
    return isBST(root->left, minval, root->data) && isBST(root->right, root->data, maxval);
}
bool isValidBST(node* root)
{
    return isBST(root,INT_MIN,INT_MAX);
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
    cout<<isValidBST(root);
    return 0;
}