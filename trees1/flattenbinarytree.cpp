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
node* prev=nullptr;
void flatten(node* root)
{
    if(root==NULL)
    {
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->right=::prev;
    root->left=NULL;
    ::prev=root;
}
void printFlattenedTree(node* root) {
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    flatten(root);
    printFlattenedTree(root);
    return 0;
}