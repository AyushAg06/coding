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
int maxpathdown(node* root,int &maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int lefth=max(0,maxpathdown(root->left,maxi));
    int righth=max(0,maxpathdown(root->right,maxi));
    maxi=max(maxi,root->data+lefth+righth);
    return max(lefth,righth)+root->data;
}
int maxpathsum(node* root)
{
    int maxi=INT_MIN;
    maxpathdown(root,maxi);
    return maxi;
}
int main()
{
    node* root=new node(-10);
    root->left=new node(9);
    root->right=new node(20);
    root->right->left=new node(15);
    root->right->right=new node(7);
    cout<<maxpathsum(root);
    return 0;
}
//       -10
//     /    \
//    9       20
//          /   \
//         15     7