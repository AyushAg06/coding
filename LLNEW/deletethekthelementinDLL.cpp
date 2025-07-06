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
        temp->back=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node* deletethekth(node* head,int k)
{
    if(head==NULL)
    {
        return NULL;
    }
    node* temp=head;
    int count=0;
    while(temp->next!=NULL)
    {
        count++;
        if(count==k)
        {
            break;
        }
        temp=temp->next;
    }
    node* prev=temp->back;
    node* front=temp->next;
    if(prev==NULL && front==NULL)
    {
        return NULL;
    }
    else if(prev==NULL)
    {
        head=temp->next;
        head->back=nullptr;
        delete temp;
        return head;
    }
    else if(front==NULL)
    {
        temp->back=nullptr;
        prev->next=nullptr;
        delete temp;
        return head;
    }
    prev->next=front;
    front->back=prev;
    delete temp;
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int k=2;
    node* head=converttoLL(arr);
    head=deletethekth(head,k);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
