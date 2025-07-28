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
bool issymmetrichelp(node* left,node* right)
{
    if(left==NULL || right==NULL)
    {
        return left==right;
    }
    if(left->data!=right->data)
    {
        return false;
    }
    return issymmetrichelp(left->left,right->right) &&
    issymmetrichelp(left->right,right->left);
}
bool issymmetric(node* root)
{
    return root==NULL || issymmetrichelp(root->left,root->right);
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(4);
    root->right->left=new node(5);
    cout<<issymmetric(root);
    return 0;
}
            //         1
            //       /   \
            //     2       2
            //   /   \   /   \
            //  4     5 5     4
