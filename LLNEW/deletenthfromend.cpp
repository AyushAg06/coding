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
    Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    if(count==n)
    {
        Node* newhead=head->next;
        delete head;
        return newhead;
    }
    int res=count-n;
    Node* temp1=head;
    while(temp1!=NULL)
    {
        res--;
        if(res==0)
        {
            break;
        }
        temp1=temp1->next;
    }
    Node* delnode=temp1->next;
    temp1->next=temp1->next->next;
    delete delnode;
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