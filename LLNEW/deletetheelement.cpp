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
Node* deletebyelement(Node* head,int val)
{
    if(head==NULL)
    {
        return head;
    }
    if(head->data==val)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=6;
    Node* head=convertarray2LL(arr);
    head=deletebyelement(head,val);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}