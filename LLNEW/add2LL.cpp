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
Node* add2LL(Node* head1,Node* head2)
{
    Node* dummyhead=new Node(-1);
    Node* current=dummyhead;
    Node* temp1=head1;
    Node* temp2=head2;
    int carry=0;
    while(temp1!=NULL||temp2!=NULL)
    {
        int sum=carry;
        if(temp1)
        {
            sum=sum+temp1->data;
            temp1=temp1->next;
        }
        if(temp2)
        {
            sum=sum+temp2->data;
            temp2=temp2->next;
        }
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        current->next=newnode;
        current=newnode;
    }
    if(carry)
    {
        Node* newnode1=new Node(carry);
        current->next=newnode1;
    }
    return dummyhead->next;
}
int main()
{
    vector<int>arr1={2,4,6,8};
    vector<int>arr2={1,3,5,2};
    Node* head1=convertarray2LL(arr1);
    Node* head2=convertarray2LL(arr2);
    Node* head=add2LL(head1,head2);
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}