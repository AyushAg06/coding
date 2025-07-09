#include<bits/stdc++.h>
using namespace std;
class node{
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
node* reverseLL(node* head)
{
    node* prev=NULL;
    node* temp=head;
    while(temp!=NULL)
    {
        node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
node* add1toLL(node* head)
{
    head=reverseLL(head);
    node* temp=head;
    int carry=1;
    while(temp!=NULL)
    {
        temp->data=temp->data+carry;
        if(temp->data<10)
        {
            carry=0;
            break;
        }
        else if(temp->data==10)
        {
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1)
    {
        head=reverseLL(head);
        node* newhead=new node(1);
        newhead->next=head;
        return newhead;
    }
    head=reverseLL(head);
    return head;
}
int main()
{
    vector<int>arr={9,9,9};
    node* head=array2LL(arr);
    head=add1toLL(head);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}
// Time complexity-O(3N)
// Space complexity-O(1)