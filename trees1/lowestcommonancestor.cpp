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
node* lowestcommonancestor(node* root,node* p,node* q)
{
    if(root==NULL||root==p||root==q)
    {
        return root;
    }
    node* left=lowestcommonancestor(root->left,p,q);
    node* right=lowestcommonancestor(root->right,p,q);
    if(left==NULL)
    {
        return right;
    }
    else if(right==NULL)
    {
        return left;
    }
    else{
        return root;
    }
}
int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    node* p=root->left->left;
    node* q=root->left->right;
    node* ans=lowestcommonancestor(root,p,q);
    cout << ans->data;
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6