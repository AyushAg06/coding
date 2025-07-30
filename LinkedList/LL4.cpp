// Check if the element is present in the linked list or not 
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
        }
};
Node* ArrayToLL(vector<int>&arr)
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
int CheckifPresent(Node* Head,int val)
{
    Node* temp=Head;
    while(temp)
    {
        if(temp->data==val)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main()
{
    vector<int>arr={2,4,6,8};
    Node* Head=ArrayToLL(arr);
    cout<<CheckifPresent(Head,6);
    return 0;