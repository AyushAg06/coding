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
node* deletethenode(node* head,int k)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==k)
        {
            if (temp->back == nullptr) {
                head = temp->next;
                if (head != nullptr)
                    head->back = nullptr;
            }
            // If it's the tail node
            else if (temp->next == nullptr) {
                temp->back->next = nullptr;
            }
           else {
                temp->back->next = temp->next;
                temp->next->back = temp->back;
            }

            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int>arr={2,4,6,8};
    int k=2;
    node* head=converttoLL(arr);
    head=deletethenode(head,k);
    node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    return 0;
}
