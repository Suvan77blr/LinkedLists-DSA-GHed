
// 270725.
/*
    P12: Finding the Intersection Point of a Y Linked List.
    (Given 2 heads we have to find their point of intersection and return that node.
        If no such intersection exists, we return NULL.
    )

        - Soln1: 
*/

#include <iostream>
#include <map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int data = -1, Node* next = nullptr) 
        : data(data), next(next) { }
};

void deleteLL(Node* head);
void displayLL(Node* head);
Node* inputLL();

// Soln1: Using MAP to compare.
Node* getIntersection_Ver1(Node* h1, Node* h2) {
    if(!h1 || !h2) return nullptr;

    map<Node*, int> mpp;
    Node* ptr = h1;

    while(ptr) {
        mpp[ptr] = 1;
        ptr = ptr->next;
    }

    ptr = h2;
    while(ptr) {
        if(mpp.find(ptr) != mpp.end()) return ptr;
        ptr = ptr->next;
    }
    return nullptr;
}

// Soln2: Adjusting Lengths and comparing.
int lengthLL(Node* head);
void adjustHead(Node*& head, int steps);
// Node* adjustHead(Node* head, int steps);

Node* getIntersection_Ver2(Node* h1, Node* h2) {
    if(!h1 || !h2) return nullptr;
    
    int n1 = lengthLL(h1);
    int n2 = lengthLL(h2);
    
    Node *p1=h1, *p2=h2;
    if(n1 != n2) {
        if(n1 > n2) {
            adjustHead(p1, n1-n2);
            // p1 = adjustHead(p1, n1-n2);
        }
        else {
            adjustHead(p2, n2-n1);
            // p2 = adjustHead(p2, n2-n1);
        }
    }

    if(!p1 || !p2) return nullptr;

    while(p1 && p2) {
        if(p1 == p2) {  return p1; }
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}

int main(void) {
    Node* head1 = inputLL();
    Node* head2 = inputLL();

    cout << "List1: ";
    displayLL(head1);
    cout << "List2: ";
    displayLL(head2);

    Node* interPt = getIntersection_Ver1(head1, head2);
    if(!interPt) {
        cout << "No Intersection & input is not a \'Y\'-LL.\n";
    }
    else {
        cout << "InterPt: " << interPt->data << endl;
    }

    deleteLL(head1);
    // Need to delete nodes in head2 only before the intersection-point.
    if(interPt) {
        Node* ptr = head2, *temp=nullptr;
        while(ptr && ptr!=interPt) {
            temp = ptr->next;
            delete ptr;
            ptr = temp;
        }
        ptr = nullptr;
    } else {
        deleteLL(head2);
    }
    return 0;
}

void deleteLL(Node* head) {
    if(!head) return;
    int count = 0;
    Node* temp = head;
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
    }
    cout << " ]\n";
    return;

}

Node* inputLL() {
    int n; cin >> n;        // Size of the LL.

    Node* dummy = new Node();
    Node* ptr = dummy;
    int ele;

    while(n) {
        cin >> ele;
        ptr->next = new Node(ele);
        ptr = ptr->next;
        n--;
    }
    Node* realHead = dummy->next;
    delete dummy;
    return realHead;
}

int lengthLL(Node* head) {
    if(!head) return 0;
    Node* ptr = head;
    int len = 0;
    while(ptr) {
        len++;
        ptr = ptr->next;
    } return len;
}

void adjustHead(Node*& head, int steps) {
    // Node* adjustHead(Node* head, int steps) {
    Node* ptr = head;
    while(steps && ptr) {
        ptr = ptr->next;
        steps--;
    }
    head = ptr;
}