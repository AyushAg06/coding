#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};
Node* deleteAllOccurrences(Node* head, int key) {
    Node* curr = head;
    while (curr) {
        if (curr->data == key) {
            Node* toDelete = curr;
            if (curr == head) {
                head = curr->next;
                if (head)
                    head->prev = nullptr;
            } else {
                if (curr->prev)
                    curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;
            }
            curr = curr->next;
            delete toDelete;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* createDLL(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return head;
}
int main() {
    int arr[] = {2, 5, 2, 7, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = createDLL(arr, n);
    cout << "Original List: ";
    printList(head);
    int key = 2;
    head = deleteAllOccurrences(head, key);
    cout << "After deleting " << key << ": ";
    printList(head);
    return 0;
}
