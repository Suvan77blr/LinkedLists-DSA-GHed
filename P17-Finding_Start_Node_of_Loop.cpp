
// 050825
/*
    P17: Finding the start of Loop in LL.
        - Soln1: Using TnH (slow-n-fast Ptrs)
        - Soln2: Using ump.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next=nullptr) 
        : data(data), next(next) { }
};

Node* getLoopStartNode_Soln1(Node* head) {
    if(!head || !head->next) return nullptr;

    // Detecting Loop.
    Node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    // No Loop exists.
    if(!fast || !fast->next) { return nullptr; }

    // Finding the start of loop.
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node* getLoopStartNode_Soln2(Node* head) {
    if( !head || !head->next) return nullptr;

    unordered_map<Node*, int> ump;
    Node* ptr = head;

    while(ptr) {
        if(ump.find(ptr) != ump.end()) {
            return ptr;
        }
        ump[ptr] = 1;
        ptr = ptr->next;
    }

    // No loop.
    return nullptr;
}