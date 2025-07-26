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

// check element is present or not 
bool check(Node* head , int target){
    Node* temp = head ;
    while(temp != nullptr){
        if(temp->data == target) return true;
        temp = temp->next;
    }
    return false;
}

// deletion of head 
Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head ;
    head = head->next;
    delete temp;
    return head;
}

// deleteion from the end 
Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head ;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp;
    return head;
}

// deletion from kth place 
Node* deleteK(Node* head , int k){
    if(k == 1){
        Node* temp = head ;
        head = head->next;
        delete temp;
        return head ;
    }
    int cnt ; 
    Node* prev = nullptr;
    Node* temp = head ;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head ;
}

// insert head 
Node* insertHead(Node* head , int val){
    Node* temp = new Node(val , head);
    return temp;
}

// insert at last 
Node* insertLast(Node* head , int val){
    if(head = nullptr){
        return new Node(val);
    }
    Node* temp = head ;
    while(temp->next != nullptr){
        temp= temp->next;
        
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head ;

}

// insert at kth position 
Node* insertK(Node* head , int val, int k){
    if(head == nullptr){
        if(k == 1){
            return new Node(val);
        }else {
            return nullptr;
        }
        if( k == 1){
            Node* temp = new Node(val , head);
            return temp;
        }
        int cnt = 0;
        Node* temp = head;
        while(temp != nullptr){
            cnt++;
            if(cnt == k -1){
                Node* x = new Node(val,temp->next);
                temp->next = x;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
}
// print the LL 
Node* print(Node* head){
    Node* temp = head ;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;  // move to the next node
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 3;
    Node* head = convert2LL(arr);
    int count = length(head);
    cout << "Length:" << count << endl;
    bool targetPresent = check(head, target);
    cout << "present or not : " << targetPresent; 
    Node* node = deleteTail(head);
    return 0;
}
