
#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data = 0, Node* next = nullptr){
            this->data = data;
            this->next = next;
        }
        ~Node() {
            if(next != nullptr) {
                delete next;
            }
        }

        void display() {
            cout << this->data << " -> ";
            if(next != nullptr) {
                next->display();
            }
        }
};

Node* getInputLL() {
    int n;
    cin >> n;

    vector<int> arr (n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i=1; i<n; i++) {
        Node* newNode = new Node(arr[i]);
        ptr = ptr->next = newNode;
    }
    return head;
}

int main(void) {
    Node* head = getInputLL();

    cout << "Input LL : ";
    // displayLL(head);
    head->display();
    cout << "|\n";

    // int idx;
    // cout << "Enter index to delete : ";

    // head = deleteLLNode(head, idx);

    // cout << "Final LL : ";
    // displayLL(head);
    // head->display();

    delete head;
    return 0;
}