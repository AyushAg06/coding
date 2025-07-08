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
node* segregate0s1s2s(node* head)
{
    node* zerohead=new node(-1);
    node* onehead=new node(-1);
    node* twohead=new node(-1);
    node* zero=zerohead;
    node* one=onehead;
    node* two=twohead;
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1)
        {
            one->next=temp;
            one=one->next;
        }
        else if(temp->data==2)
        {
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next=(onehead->next)?(onehead->next):twohead->next;
    one->next=twohead->next;
    two->next=nullptr;
    node* newhead=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return newhead;
}
int main()
{
    vector<int>arr={1,0,2,1,2,0,0,1,2};
    node* head=array2LL(arr);
    head=segregate0s1s2s(head);
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}