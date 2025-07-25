
// 250725.
/*
    P06: Odd-Even LL.
        - Soln1: Data Replacement in the LL w/ extra vector of O(n).
        - Soln2: In-place manipulation.
*/

#include <iostream>
#include <vector>
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

void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; int count=0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    }
    cout << "Deleted " << count << " nodes.\n";
}

Node* inputLL() {
    int n;
    cin >> n;

    Node* temp = new Node();
    Node* ptr = temp;
    int ele;
    for(int i=0; i<n; i++) {
        cin >> ele;
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }
    Node* actualHead = temp->next;
    delete temp;
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
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "| ]\n";
}

void oddEvenList_Soln1(Node* head) {
    if(!head || !head->next) {
        return;
    }

    vector<int> arr;
    
    // Iter1
    Node* iter = head;
    while(iter && iter->next) {
        arr.push_back(iter->data);
        iter = iter->next->next;
    }
    if(iter) {
        arr.push_back(iter->data);
    }

    // Iter2
    iter = head->next;
    while(iter && iter->next) {
        arr.push_back(iter->data);
        iter = iter->next->next;
    }
    if(iter) {
        arr.push_back(iter->data);
    }

    Node* ptr = head;
    int idx = 0;
    while(ptr) {
        ptr->data = arr[idx];
        ptr = ptr->next;
        idx++;
    }
}

void oddEvenList_Soln2(Node* head) {
    if(!head || !head->next) return;

    Node *odd=head, *even=head->next;
    Node *evenHead = even;

    while(odd && odd->next && even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
}

int main(void) {
    Node* head = inputLL();
    cout << "Input List: ";
    displayLL(head);
    
    // oddEvenList_Soln1(head);
    oddEvenList_Soln2(head);
    cout << "Result List: ";
    displayLL(head);

    deleteLL(head);

    return 0;
}