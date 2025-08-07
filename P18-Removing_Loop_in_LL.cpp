
// 050825
/*
    P18: Removing Loop in LL.
        - Finding start of loop -> Finding end of loop -> setting 'next' of end as NULL.
            ( - Soln1: Using Floyd's TnH (slow-n-fast Ptrs)
              - Soln2: Using UNORDERED_SET.
            )
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next=nullptr) 
        : data(data), next(next) { }
};

void removeLoop_Soln1(Node* head) {
    if(!head || !head->next) return;

    // Detecting Loop.
    Node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    // No Loop exists.
    if(!fast || !fast->next) return;

    // Finding the start of loop.
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* ptr = slow;
    while(ptr->next != slow) {
        ptr = ptr->next;
    }
    // Breaking the loop!
    ptr->next = nullptr;

    return;
}

void removeLoop_Soln2(Node* head) {
    if( !head || !head->next) return;

    unordered_set<Node*> ust;
    Node* prev = nullptr;
    Node* curr = head;

    // Loop detection.
    while(curr) {
        if(ust.find(curr) != ust.end()) {
            if(prev) prev->next = nullptr;
            break;
        }
        ust.insert(curr);
        prev = curr;
        curr = curr->next;
    }

    // No loop. => simply returns.
}