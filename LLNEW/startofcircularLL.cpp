#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;   
    Node* next;      
    Node(int data1, Node* next1) 
    {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
Node* startofcircularLL(Node* head)
{
    Node* temp=head;
    unordered_map<Node*,int>mpp;
    while(temp!=NULL)
    {
        if(mpp.find(temp)!=mpp.end())
        {
            return temp;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return NULL;
}
int main() { 
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; 
    Node* startnode = startofcircularLL(head);
    if (startnode!= 0) {
        cout << "Starting Node of LinkedList is : " << startnode->data << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }
    return 0;
}
