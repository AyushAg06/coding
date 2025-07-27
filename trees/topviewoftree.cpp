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
vector<int>topviewoftree(node* root)
{
    vector<int>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<pair<node*,int>>q;
    map<int,int>mpp;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        root=it.first;
        int level=it.second;
        if(mpp.find(level)==mpp.end())
        {
            mpp[level]=root->data;
        }
        if(root->left!=NULL)
        {
            q.push({root->left,level-1});
        }
        if(root->right!=NULL)
        {
            q.push({root->right,level+1});
        }
    }
    for(auto it: mpp)
    {
        ans.push_back(it.second);
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
    root->right->right=new node(6);
    vector<int>ans=topviewoftree(root);
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
