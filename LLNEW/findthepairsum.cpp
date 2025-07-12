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
node* convertArray2LL(vector<int>&arr)
{
    node* head=new node(arr[0]);
    node* temp=head;
    for(int i=1;i<arr.size();i++)
    {
        node* newnode=new node(arr[i]);
        newnode->back=temp;
        temp->next=newnode;
        temp=newnode;
    }
    return head;
}
void FindPair(node* head,int sum)
{
    node* temp1=head;
    while(temp1!=NULL)
    {
        node* temp2=temp1->next;
        while(temp2!=NULL && temp1->data+temp2->data<=sum)
        {
            if(temp1->data+temp2->data==sum)
            {
                cout<<"("<<temp1->data<<","<<temp2->data<<")\n";
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
int main()
{
    vector<int>arr={1,2,3,4,9};
    int sum=5;
    node* head=convertArray2LL(arr);
    FindPair(head,sum);
    return 0;
}