#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;        
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) 
    {
        data = data1;
        next = nullptr;
    }
};
bool detectloop(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast)
        {
            return true;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return false;
}
int main() 
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 
    if (detectloop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    return 0;
}