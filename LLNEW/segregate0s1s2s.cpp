#include<bits/stdc++.h>
using namespace std;
class Node{
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
Node* convert2LL(vector<int>&arr)
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
Node* segregate0s1s2s(Node* head)
{
    Node* temp=head;
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            cnt0+=1;
        }
        else if(temp->data==1)
        {
            cnt1+=1;
        }
        else if(temp->data==2)
        {
            cnt2+=1;
        }
        temp=temp->next;
    }
    Node* temp1=head;
    while(temp1!=NULL)
    {
        if(cnt0>0)
        {
            temp1->data=0;
            cnt0--;
        }
        else if(cnt1>0)
        {
            temp1->data=1;
            cnt1--;
        }
        else if(cnt2>0)
        {
            temp1->data=2;
            cnt2--;
        }
        temp1=temp1->next;
    }
    return head;
}
int main()
{
    vector<int>arr={1,0,2,1,2,0,0,1,2};
    Node* head=convert2LL(arr);
    head=segregate0s1s2s(head);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}