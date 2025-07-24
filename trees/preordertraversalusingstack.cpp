// preorder traversal using stack 
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
vector<int>preordertraversal(node* root)
{
    vector<int>arr;
    while(root==NULL)
    {
        return arr;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        arr.push_back(root->data);
        if(root->right!=NULL)
        {
            st.push(root->right);
        }
        if(root->left!=NULL)
        {
            st.push(root->left);
        }
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
    vector<int>ans=preordertraversal(root);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}