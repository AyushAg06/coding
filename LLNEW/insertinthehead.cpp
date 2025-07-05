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
Node* convertarraytoll(vector<int>&arr)
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
Node* insertathead(Node* head,int val)
{
    Node* temp=new Node(val);
    temp->next=head;
    head=temp;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=1;
    Node* head=convertarraytoll(arr);
    head=insertathead(head,val);
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
