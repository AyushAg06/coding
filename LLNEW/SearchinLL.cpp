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
Node* convertArraytoLL(vector<int>&arr)
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
bool searchinLL(Node* head,int val)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==val)
        {
            return true;
        }
        else
        {
            temp=temp->next;
        }
    }
    return false;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int val=6;
    Node* head=convertArraytoLL(arr);
    cout<<searchinLL(head,val);
    return 0;
}