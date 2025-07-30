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
Node* oddandevenList(Node* head)
{
    vector<int>arr;
    Node* temp1=head;
    while(temp1!=NULL)
    {
        arr.push_back(temp1->data);
        if (temp1->next == NULL) break;
        temp1=temp1->next->next;
    }
    Node* temp2=head->next;
    while(temp2!=NULL)
    {
        arr.push_back(temp2->data);
        if (temp2->next == NULL) break;
        temp2=temp2->next->next;
    }
    Node* temp=head;
    for(int i=0;i<arr.size();i++)
    {
        temp->data=arr[i];
        temp=temp->next;
    }
    return head;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
    Node* head=convert2LL(arr);
    head=oddandevenList(head);
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}