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
vector<vector<int>>leveltraversal(node* root)
{
    vector<vector<int>>ans3;
    if(root==NULL)
    {
        return ans3;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        vector<int>level;
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            root=q.front();
            q.pop();
            level.push_back(root->data);
            if(root->left!=NULL)
            {
                q.push(root->left);
            }
            if(root->right!=NULL)
            {
                q.push(root->right);
            }
        }
        ans3.push_back(level);
    }
    return ans3;
}
vector<int>rightviewoftree(node* root)
{
    vector<int>ans1;
    vector<vector<int>>levelorder1=leveltraversal(root);
    for(auto it:levelorder1)
    {
        ans1.push_back(it.back());
    }
    return ans1;
}
vector<int>leftviewoftree(node* root)
{
    vector<int>ans2;
    vector<vector<int>>levelorder2=leveltraversal(root);
    for(auto it:levelorder2)
    {
        ans2.push_back(it.front());
    }
    return ans2;
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    vector<int>ans=rightviewoftree(root);
    cout<<"rightview:-";
    for (auto level : ans) 
    {
        cout << level << " ";
    }
    cout << endl;
    vector<int>ans4=leftviewoftree(root);
    cout<<"leftview:-";
    for (auto level : ans4) 
    {
        cout << level << " ";
    }
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6