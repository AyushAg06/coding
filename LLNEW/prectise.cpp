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
node* array2LL(vector<int>&arr)
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
node* deletelast(node* head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    node* head=array2LL(arr);
    head=deletelast(head);
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}