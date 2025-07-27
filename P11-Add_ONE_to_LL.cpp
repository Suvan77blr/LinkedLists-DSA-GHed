
// 270725
/*
    P11: Adding 1 to LL.
        - Soln1: Reverse, Add 1 as carry and go on as long as 'ptr'!=NULL && 'carry'!=0.
        - Soln2: Recursive Logic, returning carry at every stage.
*/

#include <iostream>
using namespace std;

class Node{
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
Node* numToLL(int num);
Node* reverseLL(Node* head);

// Soln1: Reversal & adding.
Node* addOneToLL_Soln1(Node* head) {
    head = reverseLL(head); // Reversing the LL.

    int carry = 1, sum;
    Node* ptr = head;
    while(carry && ptr) {
        sum = ptr->data + carry;
        ptr->data = sum%10;
        carry = sum/10;
        ptr = ptr->next;
    }
    
    head = reverseLL(head); //Re-reversing the LL.
    if(carry) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}

// Soln2: Recursion & adding.
int addOneToLL_Soln2(Node* curr) {
    if(!curr) return 1;

    int carry = addOneToLL_Soln2(curr->next);
    if(!carry) return 0;

    curr->data += carry;
    carry = curr->data /10;
    curr->data %= 10;
    return carry;
}

int main(void) {
    // int num;
    // cin >> num;

    // Node* head = numToLL(num);
    // head = reverseLL(head);

    Node* head = inputLL();

    cout << "Input List: ";
    displayLL(head);
    
    int carry = addOneToLL_Soln2(head);
    if(carry) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    // head = addOneToLL_Soln1(head);


    cout << "1-added List: ";
    displayLL(head);

    deleteLL(head);
    
}

void deleteLL(Node* head) {
    if(!head) return;
    int count = 0;
    Node* temp;
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
    Node* dummy = new Node();
    Node* ptr = dummy;
    int ele;
    while(cin >> ele) {
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }
    Node* realHead = dummy->next;
    delete dummy;
    return realHead;
}

Node* numToLL(int num) {
    if(!num) return nullptr;

    Node* dummy = new Node();
    Node* ptr = dummy;

    while(num) {
        ptr->next = new Node(num%10);
        ptr = ptr->next;
        num/=10;
    }

    Node* realHead = dummy->next;
    delete dummy;
    return realHead;
}
Node* reverseLL(Node* head) {
    Node *prev=nullptr, *curr=head, *temp=nullptr;
    while(curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    } return prev;
}