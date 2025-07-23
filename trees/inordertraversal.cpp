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
vector<int>inordertraversal(node* root)
{
    vector<int>arr;
    if(root==nullptr)
    {
        return arr;
    }
    vector<int>left=inordertraversal(root->left);
    arr.insert(arr.end(),left.begin(),left.end());
    arr.push_back(root->data);
    vector<int>right=inordertraversal(root->right);
    arr.insert(arr.end(),right.begin(),right.end());
    return arr;
}
int main()
{
    node* root=new node(1);
    root->right=new node(2);
    root->right->left=new node(3);
    vector<int>ans=inordertraversal(root);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}