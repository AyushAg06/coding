#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* next;
        node* back;
    public:
        node(int data1)
        {
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};
node* converttoLL(vector<int>&arr)
{
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        node* temp=new node(arr[i]);
        prev->next=temp;
        temp->back=prev;
        prev=temp;
    }
    return head;
}
node* insertatkth(node* head,int val,int k)
{
    if(k==1)
    {
        node* temp=new node(val);
        temp->next=head;
        head->back=temp;
        head=temp;
        return head;
    }
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        if(count==k)
        {
            break;
        }
        temp=temp->next;
    }
    node* prev=temp->back;
    node* newnode=new node(val);
    newnode->next=temp;
    newnode->back=prev;
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=1;
    int k=1;
    node* head=converttoLL(arr);
    head=insertatkth(head,val,k);
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}