#include<bits/stdc++.h>
using namespace std;
class node
{
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
node* convertarray2ll(vector<int>&arr)
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
node* insertatkth(node* head,int val,int k)
{
    if(head==NULL)
    {
        if(k==1)
        {
            return new node(val);
        }
        else{
            return head;
        }
    }
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        count++;
        if(count==k-1)
        {
            node* newnode= new node(val);
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=1;
    int k=3;
    node* head=convertarray2ll(arr);
    head=insertatkth(head,val,k);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}