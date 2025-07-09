#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
    public:
        Node(int data1)
        {
            data=data1;
            next=nullptr;
        }
};
Node* convertarray2LL(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
} 
Node* deletethenthfromend(Node* head,int n)
{
    Node* fast=head;
    for(int i=0;i<n;i++)
    {
        fast=fast->next;
    }
    if(fast==NULL)
    {   
        Node* newnode=head->next;
        delete head;
        return newnode;
    }
    Node* slow=head;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    Node* newnode1=slow->next;
    slow->next=slow->next->next;
    delete newnode1;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int n=2;
    Node* head=convertarray2LL(arr);
    head=deletethenthfromend(head,n);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}