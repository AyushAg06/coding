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
bool isleaf(node* root)
{
    return (root->left==NULL) && (root->right==NULL);
}
void addleftboundary(node* root,vector<int>&ans)
{
    node* curr=root->left;
    while(curr)
    {
        if(isleaf(curr)!=true)
        {
            ans.push_back(curr->data);
        }
        if(curr->left!=NULL)
        {
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void addleaves(node* root,vector<int>&ans)
{
    if(isleaf(root))
    {
        ans.push_back(root->data);
    }
    if(root->left!=NULL)
    {
        addleaves(root->left,ans);
    }
    if(root->right!=NULL)
    {
        addleaves(root->right,ans);
    }
}
void addrightboundary(node* root,vector<int>&ans)
{
    vector<int>temp;
    node* curr=root->right;
    while(curr)
    {
        if(isleaf(curr)!=true)
        {
            temp.push_back(curr->data);
        }
        if(curr->right!=NULL)
        {
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back(temp[i]);
    }
}
vector<int>boundarytraversal(node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    if(!isleaf(root))
    {
        ans.push_back(root->data);
    }
    addleftboundary(root,ans);
    addleaves(root,ans);
    addrightboundary(root,ans);
    return ans;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(7);
    root->left->left=new node(3);
    root->left->left->right=new node(4);
    root->right->right=new node(6);
    root->right->right->left=new node(9);
    root->right->right->right=new node(10);
    vector<int>ans=boundarytraversal(root);
    for (auto val : ans) 
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}