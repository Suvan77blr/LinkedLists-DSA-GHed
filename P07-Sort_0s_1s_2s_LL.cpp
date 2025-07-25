
// 260725
/*
    Sorting a LL of 0s, 1s and 2s.
        - Soln1: Data Replacement => by counting 0s, 1s and 2s.
        - Soln2: 3 Lists and linking them!
*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data=-1, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
};

void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; int count = 0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    }
    cout << "Deleted " << count << " nodes!\n";
}

void displayLL(Node* head) {
    cout << "[ ";
    if(!head) {
        cout << "| ]\n";
        return;
    }
    Node* ptr = head;
    while(ptr) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }

    cout << "| ]\n";
}

void sort012_2PassSoln(Node* head) {
    if(!head || !head->next) return;

    int * counters = new int[3];
    for(int i=0; i<3; i++) {
        counters[i] = 0;
    }
    Node* ptr = head;

    while(ptr) {
        counters[ptr->data]++;
        ptr = ptr->next;
    }

    ptr = head;
    int cnt=0, idx=0;
    while(ptr) {
        if(cnt >= counters[idx]) {
            idx++;
            cnt = 0;
        }
        ptr->data = idx;
        ptr = ptr->next;
        cnt++;
    }
    delete[] counters;
}

Node* sort012_1PassSoln(Node* head) {
    if(!head || !head->next) return head;

    Node *zeroHead = new Node(), *oneHead = new Node(), *twoHead = new Node();
    Node *zero=zeroHead, *one=oneHead, *two=twoHead;
    
    Node* ptr = head;
    while(ptr) {
        if(ptr->data == 0) {
            zero->next = ptr;
            zero = zero->next;
        }
        else if(ptr->data == 1) {
            one->next = ptr;
            one = one->next;
        }
        else {
            two->next = ptr;
            two = two->next;
        }
        ptr = ptr->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node* actualHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return actualHead;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n; cin >> n;

    Node* dummy = new Node(-1);
    Node* ptr = dummy;
    int ele;
    while(cin >> ele) {
    // for(int i=0; i<n; i++) {
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }

    cout << "Orig List: ";
    displayLL(dummy->next);
    
    dummy->next = sort012_1PassSoln(dummy->next);
    // sort012_2PassSoln(dummy->next);

    cout << "Srtd List: ";
    displayLL(dummy->next);

    deleteLL(dummy);
    return 0;
}

/*
    TC:
    1 0 1 2 0 2 1 0
*/