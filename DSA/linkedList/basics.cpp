#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Convert vector to Linked List
Node* convert2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;     // link current node to new node
        mover = temp;           // move the pointer ahead
    }

    return head;
}
// length of ll ---
int length(Node* head){
    int cnt = 0; 
    Node* temp = head ; 
    while(temp != nullptr){
        temp = temp->next;
        cnt++;
    }
    return cnt ;
}
bool check(Node* head , int target){
    Node* temp = head ;
    while(temp != nullptr){
        if(temp->data == target) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 3;
    Node* head = convert2LL(arr);

    // Traversal
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;  // move to the next node
    }
    cout << endl;
    int count = length(head);
    cout << "Length:" << count << endl;
    bool targetPresent = check(head, target);
    cout << "present or not : " << targetPresent; 
    return 0;
}
