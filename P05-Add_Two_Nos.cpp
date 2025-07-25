
// 250725.
/*
    Adding two numbers using Linked Lists.
*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

void deleteLL(Node* head) {
    if(!head) return;
    Node* temp;
    int count = 0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    }
    cout << "Deleted nodes: " << count << endl;
}

void displayLL(Node* head) {
    if(!head) {
        cout << "EMPTY LIST\n";
        return;
    }

    Node* ptr = head;
    cout << "[ ";
    while(ptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } cout << "| ]\n";
}

Node* numToLL(int num, bool isNegative=false) {
    if(num == 0) {
        return nullptr;
    }

    // int digit = num%10;
    // num /= 10;
    // Node* head = new Node(digit);
    // Node* ptr = head;
    Node* dummy = new Node(-1);
    Node* ptr = dummy;

    while(num != 0) {
        ptr->next = new Node(num %10);
        // ptr->next = newNode;
        ptr = ptr->next;
        num /= 10;
    }
    Node* actualHead = dummy->next;
    delete dummy;
    return actualHead;
}

int llToNum(Node* head, bool isNegative=false) {
    if(!head) {
        return 0;
    }

    Node* ptr = head;
    int num = 0, factor=1;

    while(ptr) {
        num = num + ptr->data*factor;
        ptr = ptr->next;
        factor *= 10;
    }
    cout << "\n";
    return num;
}

int addLists(Node* h1, Node* h2) {
    if(!h1) return llToNum(h2);
    if(!h2) return llToNum(h1);

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    Node *t1 = h1, *t2=h2;
    // Node* t2 = h2;
    int sum, carry=0;
    while(t1 || t2) {
        sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        
        curr->next = new Node(sum %10);
        // Node* newNode = new Node(sum %10);
        // curr->next = newNode;
        curr = curr->next;

        carry = sum/10;
        
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    
    if(carry) {
        curr->next = new Node(carry);
        // Node* newNode = new Node(carry);
        // curr->next = newNode;
    }

    int res = llToNum(dummy->next);
    deleteLL(dummy);
    return res;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num1, num2;
    cin >> num1 >> num2;

    Node* ll1 = numToLL(num1);
    Node* ll2 = numToLL(num2);

    displayLL(ll1);
    displayLL(ll2);

    int number = addLists(ll1, ll2);
    cout << "Final Sum: " << number << endl;

    deleteLL(ll1);
    deleteLL(ll2);
}

// Earlier Version:
/*
int addLists(Node* h1, Node* h2) {
    if(!h1) {
        return llToNum(h2);
    }
    if(!h2) {
        return llToNum(h1);
    }

    Node* p1 = h1;
    Node* p2 = h2;

    int carry = 0;
    int sum = p1->data+p2->data;
    carry = sum/10;
    sum %= 10;
    Node* sumHead = new Node(sum);
    p1 = p1->next;
    p2 = p2->next;

    Node* ptr = sumHead;
    
    while(p1 && p2) {
        sum = p1->data + p2->data + carry;
        if(sum >= 10) {
            carry = sum /10;
            sum %= 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        ptr->next = newNode;
        ptr = ptr->next;

        p1 = p1->next;
        p2 = p2->next; 
    }

    while(p1) {
        sum = p1->data + carry;
        if(sum >= 10) {
            carry = sum /10;
            sum %= 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        ptr->next = newNode;
        ptr = ptr->next;

        p1 = p1->next;
    }

    while(p2) {
        sum = p2->data + carry;
        if(sum >= 10) {
            carry = sum /10;
            sum %= 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        ptr->next = newNode;
        ptr = ptr->next;

        p2 = p2->next;
    }

    if(carry > 0) {
        ptr->next = new Node(carry);
    }

    cout << "Sum: ";
    displayLL(sumHead);
    int result = llToNum(sumHead);

    deleteLL(sumHead);
    return result;
}
*/