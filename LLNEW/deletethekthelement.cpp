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
Node* ConvertArray2LL(vector<int>&arr)
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
Node* deletekthelement(Node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        count++;
        if(count==k)
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
    int k=3;
    Node* head=ConvertArray2LL(arr);
    head=deletekthelement(head,k);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
