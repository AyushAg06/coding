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
node* deletemiddlenode(node* head)
{
    node* fast=head;
    node* slow=head;
    node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    node* head=converttoLL(arr);
    head=deletemiddlenode(head);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}