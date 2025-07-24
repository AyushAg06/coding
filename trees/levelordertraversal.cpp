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
vector<vector<int>>levelordertraversal(node* root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++)
        {
            node* dummynode=q.front();
            q.pop();
            if(dummynode->left!=NULL)
            {
                q.push(dummynode->left);
            }
            if(dummynode->right!=NULL)
            {
                q.push(dummynode->right);
            }
            level.push_back(dummynode->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    vector<vector<int>>ans=levelordertraversal(root);
    for (auto level : ans) 
    {
        for (int val : level) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}