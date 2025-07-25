
// 200525.
/*
    Linked List deletion Program.
    Deleting the node of the LL based on INDEX.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data=0, Node* next=nullptr) {
            this->data = data;
            this->next = next;
        }
};

Node* getLinkedList(int n);
void printLinkedList(Node* head);
void deleteLinkedList(Node* head);

Node* deleteByIdx(Node* head, int idx, bool& result, int& deleted) {
    if(head == nullptr) {
        result = false;
        return nullptr;
    }

    if(idx == 0) {
        // Delete head.
        Node* temp = head->next;
        deleted = head->data;
        delete head;
        result = true;
        head = temp;
        return head;
    }
    // int count = 0;
    // Node* ptr = head;
    // while(count != idx && ) {
    //     ptr = 
    // }
}

int main(void) {
    int n;
    // cout << "Enter the LL size : ";
    cin >> n;

    Node* head = getLinkedList(n);
    
    int deleted = NULL;
    bool result = false;
    
    int idx;
    // cout << "Enter the index to delete: ";
    cin >> idx;

    head = deleteByIdx(head, idx, result, deleted);
    if(result) {
        cout << "Deleted: " << deleted << endl;
    }

    cout << "Current Linked-List: ";
    printLinkedList(head);
    deleteLinkedList(head);
}

Node* getLinkedList(int n) {
    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i=1; i<n; i++) {
        Node* newNode = new Node(arr[i]);
        ptr->next = newNode;
        ptr = ptr->next;
    }

    return head;
}

void printLinkedList(Node* head) {
    if(head == NULL){
        // cout << "Empty Linked-List!\n";
        return;
    }

    Node* ptr = head;

    while(ptr != nullptr) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "|\n";
}

void deleteLinkedList(Node* head) {
    if(head == nullptr) {
        return;
    }

    Node* ptr = head;
    Node* temp;
    int count = 0;
    while(ptr != nullptr) {
        temp = ptr->next;
        delete ptr;
        ptr = temp;
        count++;
    }
    cout << "Deleted " << count << " nodes!\n";
    return;
}
