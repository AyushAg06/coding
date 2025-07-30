// write a program to convert a array into LinkedList
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1)
        {
            data=data1;
            next=next1;
        }
        Node(int data1)
        {
            data=data1;
        }
};
Node* convertarray2LL(vector<int>&arr)
{
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=0;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    Node* head=convertarray2LL(arr);
    cout<<head->next;
    return 0;
}
// time-complexity=O(n)
// space-complexity=O(1)