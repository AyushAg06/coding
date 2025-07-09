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
bool checkpalindrome(node* head)
{
    node*temp=head;
    stack<int>st;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;
    }
    node* temp1=head;
    while(temp1!=NULL)
    {
        if(temp1->data!=st.top())
        {
            return false;
        }
        st.pop();
        temp1=temp1->next;
    }
    return true;
}
int main()
{
    vector<int>arr={1,2,1};
    node* head=array2LL(arr);
    cout<<checkpalindrome(head);
    return 0;
}