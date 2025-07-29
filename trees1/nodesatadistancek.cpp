#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data1) {
        data = data1;
        left = right = nullptr;
    }
};
// Step 1: Mark parent for all nodes
void markParent(Node* root, unordered_map<Node*, Node*>& parent_track) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

// Step 2: BFS to find all nodes at distance K
vector<int> distanceK(Node* root, Node* target, int k) {
    unordered_map<Node*, Node*> parent_track;
    markParent(root, parent_track);

    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(target);
    visited.insert(target);

    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        if (dist == k) break;
        dist++;
        for (int i = 0; i < size; ++i) {
            Node* current = q.front();
            q.pop();

            if (current->left && !visited.count(current->left)) {
                visited.insert(current->left);
                q.push(current->left);
            }
            if (current->right && !visited.count(current->right)) {
                visited.insert(current->right);
                q.push(current->right);
            }
            if (parent_track.count(current) && !visited.count(parent_track[current])) {
                visited.insert(parent_track[current]);
                q.push(parent_track[current]);
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->data);
        q.pop();
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);

    Node* target = root->left; // node 2
    int k = 2;

    vector<int> ans = distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target " << target->data << ": ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
