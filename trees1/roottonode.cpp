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
bool getpath(node* root,int x,vector<int>&arr) 
{
    if(root==NULL)
    {
        return false;
    }
    arr.push_back(root->data);
    if(root->data==x)
    {
        return true;
    }
    if(getpath(root->left,x,arr)||getpath(root->right,x,arr))
    {
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int>roottonode(node* root,int x)
{
    vector<int>arr;
    if(root==NULL)
    {
        return arr;
    }
    getpath(root,x,arr);
    return arr;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    int x=5;
    vector<int>ans=roottonode(root,x);
    for (auto level : ans) 
    {
        cout << level << " ";
    }
    cout << endl;
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6