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
int maxDepth(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return 1+max(left,right);
}
int diameteroftree(node* root)
{

    if(root==NULL)
    {
        return 0;
    }
    int maxi=0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    maxi=max(maxi,(left+right));
    diameteroftree(root->left);
    diameteroftree(root->right);
    return maxi;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(5);
    root->right->left->right=new node(6);
    cout<<maxDepth(root);
    return 0;
}