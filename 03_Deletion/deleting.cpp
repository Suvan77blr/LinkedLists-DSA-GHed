
// 200525.
/*
    Linked List deletion Program.
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

int main(void) {
    int n;
    // cout << "Enter the LL size : ";
    cin >> n;

    Node* head = getLinkedList(n);
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