
// 260725
/*
    P08: Remove Nth Node from the End.
        - 1pass Solution - Fast-Slow Ptr.
        - 2pass Solution - Calc len and then move to 'len-N' th node and then delete.

*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data=-1, Node* next=nullptr) {
        this->data = data;
        this->next = next;
    }
};

// Helper Functions.
void deleteLL(Node* head);
void displayLL(Node* head);
Node* inputLL();

// Main-Core functions.
// 1-pass solution.
Node* removeNthNodeFromEnd_Soln2(Node* head, int n) {
    if(!head) return head;

    Node* fast = head;
    // while(n) {
    for(int i=0; i<n; i++) {
        fast = fast->next;
        // n--;
    }
    if(!fast) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }
    Node* slow = head;
    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}

// 2-pass solution.
Node* removeNthNodeFromEnd_Soln1(Node* head, int n) {
    int len = 0;
    Node* ptr = head;
    while(ptr) {
        len++;
        ptr = ptr->next;
    }
    cout << "Length: " << len << "\n";

    if(n == len) {
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    int targetNodeIdx = len-n;
    ptr = head;
    while(ptr) {
        targetNodeIdx--;
        if(!targetNodeIdx)
            break;
        ptr = ptr->next;
    }
    
    Node* toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;

    return head;
}

int main(void) {
    Node* head = inputLL();
    int n; cin >> n;

    cout << "Orig List: ";
    displayLL(head);

    head = removeNthNodeFromEnd_Soln2(head, n);
    // head = removeNthNodeFromEnd_Soln1(head, n);
    
    cout << "Final List: ";
    displayLL(head);
    deleteLL(head);

    return 0;
}

// Helper Functions definitions.
void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; int count=0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    }
    cout << "Deleted " << count << " nodes.\n";
}

void displayLL(Node* head ){
    cout << "[ ";
    if(!head) {
        cout << "| ]\n";
        return;
    }
    
    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } cout << "| ]\n";
}

Node* inputLL() {
    int len; cin >> len;
    Node* dummy = new Node();
    Node* ptr = dummy;

    int ele;
    while(len > 0) {
        cin >> ele;
        ptr->next = new Node(ele);
        ptr = ptr->next;
        len--;
    }
    Node* actualHead = dummy->next;
    delete dummy;
    return actualHead;
}
