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
vector<vector<int>>zigzagtraversal(node* root)
{
    vector<vector<int>>ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<node*>q;
    q.push(root);
    bool lefttoright=true;
    while(!q.empty())
    {
        int n=q.size();
        vector<int>row(n);
        for(int i=0;i<n;i++)
        {
            root=q.front();
            q.pop();
            int index=(lefttoright)?i:n-i-1;
            row[index]=root->data;
            if(root->left!=NULL)
            {
                q.push(root->left);
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
            }
        }
        lefttoright=!(lefttoright);
        ans.push_back(row);
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
    vector<vector<int>>ans=zigzagtraversal(root);
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