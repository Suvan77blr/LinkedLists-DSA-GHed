
// 260725.
/*
    P09: Reversing a LL.
        - Soln1: Using Stack.
        - Soln1: Recursion.
        - Soln1: Iterative, 3-pointer solution.
*/

#include <iostream>
#include <stack>
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

void deleteLL(Node* head);
void displayLL(Node* head);
Node* inputLL();

// Version1: Using Stack.
Node* reverseLL(Node* head) {
    if(!head || !head->next) return head;

    stack<int> stk;
    Node* temp = head;
    while(temp) {
        stk.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp) {
        temp->data = stk.top();
        stk.pop();
        temp = temp->next;
    }

    return head;
}

// Version2: Recursion.
Node* recReversal(Node* curr) {
    if(!curr || !curr->next) return curr;

    Node* newHead = recReversal(curr->next);
    Node* front = curr->next;
    front->next = curr;
    curr->next = nullptr;
    return newHead;
}

// Version3: Iterative, 3Pointers Solution.
Node* iterReversal(Node* head) {
    if(!head || !head->next) return head;

    Node *prev=nullptr, *curr=head, *temp=nullptr;
    while(curr != nullptr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(void) {
    Node* head = inputLL();
    cout << "Orig List: ";
    displayLL(head);
    
    // Version1.
    // head = reverseLL(head);

    // Version2.
    head = recReversal(head);

    // Version3.
    // head = iterReversal(head);
    
    cout << "Rvrsed List: ";
    displayLL(head);

    deleteLL(head);
    return 0;
}

Node* inputLL() {
    // int n; cin >> n;
    Node* dummy = new Node();
    Node* ptr = dummy;
    int ele;

    while(cin >> ele) {
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }

    Node* actualHead = dummy->next;
    delete dummy;
    return actualHead;
}

void displayLL(Node* head) {
    cout << "[ ";
    if(!head) {
        cout << "| ]\n";
        return;
    }
    Node* ptr = head;
    while(ptr) {
        cout << ptr-> data << "->";
        ptr = ptr->next;
    }
    cout << "| ]\n";
}

void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; int count = 0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    }   cout << "Deleted " << count << " nodes.\n";
}