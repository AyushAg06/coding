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
bool checkpalindrome(node* head)
{
    node* slow=head;
    node* fast=head;
    while(fast!=NULL&& fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    node* newhead=reverseLL(slow->next);
    node* first=head;
    node* second=newhead;
    while(second!=NULL)
    {
        if(first->data!=second->data)
        {
            reverseLL(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newhead);
    return true;
}
int main()
{
    vector<int>arr={1,2,1};
    node* head=array2LL(arr);
    cout<<checkpalindrome(head);
    return 0;
}