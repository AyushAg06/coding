#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node* back;
    public:
        node(int data1)
        {
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};
node* converttoLL(vector<int>&arr)
{
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        node* temp=new node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}
void insertatnode(node* nodes,int val)
{
    node* prev=nodes->back;
    node* newnode=new node(val);
    newnode->back=prev;
    newnode->next=nodes;
    prev->next=newnode;
    nodes->back=newnode;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=1;
    node* head=converttoLL(arr);
    insertatnode(head->next->next,val);
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}