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
int findmiddlenode(node* head)
{
    int length=0;
    node* temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    int middle=(length/2)+1;
    while(head!=NULL)
    {
        middle=middle-1;
        if(middle==0)
        {
            break;
        }
        head=head->next;
    }
    return head->data;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6};
    node* head=array2LL(arr);
    cout<<findmiddlenode(head);
    return 0;
}
// Time complexity-O(3N)
// Space complexity-O(1)