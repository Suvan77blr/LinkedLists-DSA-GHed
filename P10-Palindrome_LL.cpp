
// 260725
/*
    P10: Checking if given LL is Palindrome or not.
        - Soln1: Using Stack.
        - Soln2: node-before-mid, reverse 2nd half and compare. (reverse-back 2nd half in the end)
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
Node* reverseLL(Node* head);

// Solution1: Using stack. 
bool isPalindrome_Ver1(Node* head) {
    if(!head || !head->next) return true;

    stack<int> stk;
    // Accumulation Iter.
    Node* ptr = head;
    while(ptr) {
        stk.push(ptr->data);
        ptr = ptr->next;
    }

    // Verification Iter.
    ptr = head;
    bool result = true;
    while(ptr) {
        if(ptr->data != stk.top()) {
            result = false;
            break;
        }
        stk.pop();
        ptr = ptr->next;
    }
    return result;
}

// Solution2: Finding 'node-before-mid', reversing and checking.
bool palindromeChecker(Node* h1, Node* h2);     // To check both halves of list.
bool isPalindrome_Ver2(Node* head) {
    if(!head || !head->next) return true;

    Node *slow=head, *fast=head;

    while(fast->next && fast->next->next) {
        slow = slow->next;          // Tortoise.
        fast = fast->next->next;    // Hare.
    }

    Node* newHead = reverseLL(slow->next);
    bool result = palindromeChecker(head, newHead);
    reverseLL(newHead);

    return result;
}

bool palindromeChecker(Node* h1, Node* h2) {
    Node *ptr1=h1, *ptr2=h2;

    while(ptr2) {
        if(ptr2->data != ptr1->data) return false;
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    return true;
}


int main(void) {
    Node* head = inputLL();
    cout << "Input List: ";
    displayLL(head);

    bool result = isPalindrome_Ver2(head);
    cout << "This a \'Palindrome\' LL? : " << (result ? "YES\n" : "NO\n");

    deleteLL(head);
    return 0;
}

void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; 
    int count = 0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    } cout << "Deleted " << count << " nodes.\n";
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

Node* inputLL() {
    int n;
    cin >> n;

    Node* dummy = new Node();
    Node* ptr = dummy;
    
    int ele;
    for(int i=0; i<n; i++) {
        cin >> ele;
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }
    Node* realHead = dummy->next;
    delete dummy;
    return realHead;
}


Node* reverseLL(Node* head) {
    if(!head) return head;
    Node *prev=nullptr, *curr=head, *temp=nullptr;
    while(curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}