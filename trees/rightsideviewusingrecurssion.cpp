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
void recurssion1(node* root,int level,vector<int>& res)
{
    if(root==NULL)
    {
        return;
    }
    if(level==res.size())
    {
        res.push_back(root->data);
    }
    recurssion1(root->right,level+1,res);
    recurssion1(root->left,level+1,res);
}
vector<int>rightviewoftree(node* root)
{
    vector<int>res;
    recurssion1(root,0,res);
    return res;
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
    return 0;
}
            //         1
            //       /   \
            //     2       3
            //   /   \      \
            //  4      5      6