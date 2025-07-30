#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* next;
    public:
        node(int data1)
        {
            data=data1;
            next=nullptr;
        }
};
node* convertarray2ll(vector<int>&arr)
{
    node* head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
node* insertatlast(node* head,int val)
{
    if(head==NULL)
    {
        return new node(val);
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* newnode=new node(val);
    temp->next=newnode;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=1;
    node* head=convertarray2ll(arr);
    head=insertatlast(head,val);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
