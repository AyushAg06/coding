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
node *SearchBst(node *root, int val)
{
    while (root != NULL && root->data != val)
    {
        if (val < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
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
    int val = 10;
    node *result=SearchBst(root, val);
    cout<<result->data;
    return 0;
}

