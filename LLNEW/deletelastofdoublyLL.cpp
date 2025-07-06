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
        temp->back=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node* deletelast(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node* prev=temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    delete temp;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    node* head=converttoLL(arr);
    head=deletelast(head);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}