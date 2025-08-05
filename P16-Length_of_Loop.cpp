
// 050825
/*
    Finding the length of the loop.
        - Soln1: Slow & Fast Pointers.
        - Soln2: Using ump<Node*, nodeCntr>.
*/

#include <iostream>
using namespace std;

class Solution {
    public:
        int lengthOfLoop_UMP(Node *head);
        int lengthOfLoop_TnH(Node &head);
};

int Solution :: legnthOfLoop_TnH(Node *head) {
    if(!head || !head->next) return 0;  // No cycle.
    
    Node *slow=head, *fast=head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            int cnt = 0;
            do {
                fast = fast->next;
                cnt++;
            } while(fast != slow);
            return cnt;
        }
    }

    return 0;   // No cycle.
}

int Solution :: lengthOfLoop_UMP(Node *head) {
    if(!head || head->next==NULL) return 0;     // No cycle.
    unordered_map<Node*, int> ump;
    
    Node* ptr = head;
    int nodeCnter = 1;
    while(ptr != NULL) {
        if(ump.find(ptr) != ump.end()) 
        {
            // Cycle exists.
            return nodeCnter - ump[ptr];
        }
        ump[ptr] = nodeCnter;
        nodeCnter++;
        ptr = ptr->next;
    }
    
    return 0;   // No cycle.
}