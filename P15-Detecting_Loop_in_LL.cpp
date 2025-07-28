
// 280725.
/*
    P15: Detecting Loop in LL.
        - Soln1: Using unordered_map.
        - Soln2: Tortoise & Hare => 2Pointer soln.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data=-1, Node* next=nullptr)
        : data(data), next(next) { }
};

void safeDeleteLL(Node* head);
Node* inputLL();
void displayLL(Node* head);

// Tortoise & Hare.
bool hasLoop_Soln2(Node* head) {
    if(!head || !head->next) return false;
    Node *slow=head, *fast=head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

// UMP-based soln.
bool hasLoop_Soln1(Node* head) {
    if(!head || !head->next) return false;

    unordered_map<Node*, int> ump;
    Node* ptr = head;

    while(ptr) {
        if(ump.find(ptr) != ump.end()) {
            return true;
        }
        ump[ptr] = 1;
        ptr = ptr->next;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = inputLL();
    // displayLL(head);

    // bool result = hasLoop_Soln2(head);
    bool result = hasLoop_Soln1(head);
    
    cout << "LL has loop?: " << (result ? "YES.\n" : "NO.\n");

    // deleteLL(head);
    safeDeleteLL(head);
    return 0;
}

// void deleteLL(Node* head) {
//     if(!head) return;
//     Node* temp;
//     int count;
//     while(head) {
//         temp = head->next;
//         delete head;
//         head = temp;
//         count++;
//     } cout << "Delete " << count << " nodes.\n";
// }

void safeDeleteLL(Node* head) {
    unordered_set<Node*> visited;
    Node* curr = head;
    int count = 0;

    while (curr) {
        if (visited.count(curr)) {
            cout << "Loop detected during deletion. Stopping to prevent infinite loop.\n";
            break;
        }
        visited.insert(curr);
        Node* temp = curr->next;
        delete curr;
        curr = temp;
        count++;
    }

    cout << "Deleted " << count << " nodes safely.\n";
}

Node* inputLL() {
    Node* dummy = new Node();
    Node* ptr = dummy;
    vector<Node*> nodes; // Keep track of all nodes to access any by position
    int ele;

    // cout << "Enter elements (non-integer to stop):\n";
    while(cin >> ele) {
        ptr->next = new Node(ele);
        ptr = ptr->next;
        nodes.push_back(ptr);
    }

    cin.clear(); // clear fail state
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // cout << "Enter loop position (0-based, -1 for no loop): ";
    int loopPos;
    cin >> loopPos;

    if(loopPos >= 0 && loopPos < nodes.size()) {
        ptr->next = nodes[loopPos];
        cout << "Loop created: last node points to node at position " << loopPos << ".\n";
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