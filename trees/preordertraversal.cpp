#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node *left;
        node *right;
        node(int data1)
        {
            data=data1;
            left=right=nullptr;
        }
};
vector<int>preordertraversal(node* root)
{
    vector<int>arr;
    if(root==nullptr)
    {
        return arr;
    }
    arr.push_back(root->data);
    vector<int>left=preordertraversal(root->left);
    vector<int>right=preordertraversal(root->right);
    arr.insert(arr.end(),left.begin(),left.end());
    arr.insert(arr.end(),right.begin(),right.end());
    return arr;
}
int main() {
    // Creating the tree:
    //       1
    //        \
    //         2
    //        / 
    //       3
    node* root = new node(1);
    root->right = new node(2);
    root->right->left = new node(3);
    vector<int> result = preordertraversal(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}