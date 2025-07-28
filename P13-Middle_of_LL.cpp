
// 280725.
/*
    P13: Finding the middle node of the LL.
        - Soln1: Find length & go to the [(N/2)]th Node.
        - Soln2: Tortoise & Hare => 2Pointer soln.
*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data=-1, Node* next=nullptr)
        : data(data), next(next) { }
};

void deleteLL(Node* head);
Node* inputLL();
void displayLL(Node* head);

// Tortoise & Hare.
Node* getMiddleNode_Soln2(Node* head) {
    Node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Length-based soln.
Node* getMiddleNode_Soln1(Node* head) {
    int len = 0;
    Node* ptr = head;

    while(ptr) {
        ptr = ptr->next;    
        len++;
    }
    int midNodeSteps = (len/2);
    
    ptr = head;
    while(midNodeSteps-- && ptr) {
        ptr = ptr->next;
    }
    // int idx=0;
    // while(idx<midNodeSteps && ptr) {
    //     ptr = ptr->next;
    //     idx++;
    // }
    return ptr;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = inputLL();
    cout << "Input List: ";
    displayLL(head);

    Node* midNode = getMiddleNode_Soln2(head);
    // Node* midNode = getMiddleNode_Soln1(head);
    cout << "Middle Node: " << midNode->data << "\n";

    deleteLL(head);
    return 0;
}

void deleteLL(Node* head) {
    if(!head) return;
    Node* temp;
    int count;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    } cout << "Delete " << count << " nodes.\n";
}

Node* inputLL() {
    Node* dummy = new Node();
    Node* ptr = dummy;
    int ele;

    while(cin >> ele) {
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }
    Node* head = dummy->next;
    delete dummy;
    return head;
}

void displayLL(Node* head) {
    if(!head) {
        cout << "[ | ]\n";
        return;
    }
    cout << "[ ";
    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } cout << "| ]\n";
}