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
int findlength(Node* slow,Node* fast)
{
    int count=1;
    fast=fast->next;
    while(fast!=slow)
    {
        count++;
        fast=fast->next;
    }
    return count;
}
int lengthOfLoop(Node* head) {
    if(head==NULL||head->next==NULL)
    {
        return 0;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return findlength(slow,fast);
        }
    }
    return 0;
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
    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }
    return 0;
}
