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
vector<int>postordertraversal(node* root)
{
    vector<int>arr;
    if(root==NULL)
    {
        return arr;
    }
    stack<node*>st1,st2;
    st1.push(root);
    while(!st1.empty())
    {
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL)
        {
            st1.push(root->left);
        }
        if(root->right!=NULL)
        {
            st1.push(root->right);
        }
    }
    while(!st2.empty())
    {
        arr.push_back(st2.top()->data);
        st2.pop();
    }
    return arr;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);
    vector<int>ans=postordertraversal(root);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}