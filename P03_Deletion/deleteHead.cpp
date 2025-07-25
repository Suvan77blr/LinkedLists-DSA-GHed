
// 200525.
/*
    Linked List deletion Program.
    Deleting the HEAD of the LL.
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

Node* deleteHead(Node* head, bool& result, int& deleted) {
    if(head == nullptr){
        result = false;
        return nullptr;
    }

    deleted = head->data;
    Node* temp = head->next;
    delete head;
    head = temp;
    result = true;
    return head;
}

int main(void) {
    int n;
    // cout << "Enter the LL size : ";
    cin >> n;

    Node* head = getLinkedList(n);
    
    int deleted = NULL;
    bool result = false;
    while(head) {
        head = deleteHead(head, result, deleted);
        if(!result) {
            cout << "Empty Linklist!";
            break;
        }
        else {
            cout << "Deleted: " << deleted << endl;
        }
        cout << "Current Linked-list : ";
        printLinkedList(head);
        cout << "\n";
    }

    cout << "Ending the program ... \n";
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