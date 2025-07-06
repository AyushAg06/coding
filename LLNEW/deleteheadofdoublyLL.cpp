#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1)
        {
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};
Node* converttodoublyLL(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        temp->back=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
Node* deleteHead(Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    head->back=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    Node* head=converttodoublyLL(arr);
    head=deleteHead(head);
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}