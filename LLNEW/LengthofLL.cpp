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
Node* convertArray2LL(vector<int>&arr)
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
int LengthofLL(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
int main()
{
    vector<int>arr={2,4,5,6};
    Node* head=convertArray2LL(arr);
    cout<<LengthofLL(head);
    return 0;
}