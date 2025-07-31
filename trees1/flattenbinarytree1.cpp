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
void flatten(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>st;
    st.push(root);
    while(st.empty())
    {
        node* curr=st.top();
        st.pop();
        if(curr->right!=NULL)
        {
            st.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            st.push(curr->left);
        }
        if(!st.empty())
        {
            curr->right=st.top();
        }
        root->left=NULL;
    }
}
void printFlattenedTree(node* root) {
    if(!root){
        return;
    }
    cout << root->data << " ";
    printFlattenedTree(root->left);
    printFlattenedTree(root->right);
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    flatten(root);
    printFlattenedTree(root);
    return 0;
}