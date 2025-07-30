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
    stack<node*>st;
    // node* dummynode=root;
    while(true)
    {
        // if(dummynode!=NULL)
        if(root!=NULL)
        {
            // st.push(dummynode);
            st.push(root);
            // dummynode=dummynode->left;
            root=root->left;
        }
        else{
            if(st.empty()==true)
            {
                break;
            }
            // dummynode=st.top();
            root=st.top();
            st.pop();
            // arr.push_back(dummynode->data);
            // dummynode=dummynode->right;
            arr.push_back(root->data);
            root=root->right;
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
    vector<int>ans=inordertraversal(root);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}