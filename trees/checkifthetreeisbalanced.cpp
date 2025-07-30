#include<bits/stdc++.h>
using namespace std;
class node{
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
int maxheight(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=maxheight(root->left);
    if(left==-1)
    {
        return -1;
    }
    int right=maxheight(root->right);
    if(right==-1)
    {
        return -1;
    }
    if(abs(left-right)>1)
    {
        return -1;
    }
    return max(left,right)+1;
}
bool checkbalanced(node* root)
{
    return maxheight(root)!=-1;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->right->left=new node(4);
    root->right->right=new node(5);
    root->right->left->right=new node(6);
    cout<<checkbalanced(root);
    return 0;
}