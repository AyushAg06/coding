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
int widthoftree(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=0;
    queue<pair<node*,int>>q;
    q.push({root,0});
    while(!q.empty())
    {
        int n=q.size();
        int first,last;
        int min=q.front().second;
        for(int i=0;i<n;i++)
        {
            int curr_id=q.front().second-min;
            root=q.front().first;
            q.pop();
            if(i==0)
            {
                first=curr_id;
            }
            if(i==n-1)
            {
                last=curr_id;
            }
            if(root->left!=NULL)
            {
                q.push({root->left,curr_id*2+1});
            }
            if(root->right!=NULL)
            {
                q.push({root->right,curr_id*2+2});
            }
        }
        ans=max(ans,last-first+1);
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
    int x=5;
    cout<<widthoftree(root);
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6