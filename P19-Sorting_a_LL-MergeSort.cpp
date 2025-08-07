
// 070825
/*
    P19: Sorting a LL.
        - Soln1: Using LL-based MergeSort.
        - Soln2: Using 2ndary Array/Vector.
*/

#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Node {
    public:
    int data; Node* next;

    Node(int data=-1, Node* next=nullptr)
        : data(data), next(next) { }
};

void myMerge(vi& arr, int left, int mid, int right);
void myMergeSort(vi& arr, int left, int right);


Node* getMiddleNode_Modified(Node* head);
Node* merge2(Node* left, Node* right);

Node* sorting_Soln1(Node* head) {
    if (!head || !head->next) return head;

    Node* middleNode = getMiddleNode_Modified(head);
    Node* leftHead = head;
    Node* rightHead = middleNode->next;
    middleNode->next = nullptr;

    leftHead = sorting_Soln2(leftHead);
    rightHead = sorting_Soln2(rightHead);

    return merge2(leftHead, rightHead);
}

// Function to merge 2 sorted LLs.
Node* merge2(Node* left, Node* right) {
    if(!left) return right;
    if(!right) return left;

    // Node* dummy = new Node(-1);
    Node dummy(-1);     // Stack allocation.
    Node* ptr = &dummy;

    while(left!=nullptr && right!=NULL) {
        if(left->data < right->data) {
            ptr->next = left;
            left = left->next;
        }
        else {
            ptr->next = right;
            right = right->next;
        }
        ptr = ptr->next;
    }

    ptr->next = (left != NULL) ? left : right;
    return dummy.next;
}

// Function to get the middle node.  (left-mid in even cases.)
Node* getMiddleNode_Modified(Node* head) {
    if(!head || !head->next) return head;

    Node *slow=head, *fast=head->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    } return slow;
}

Node* sorting_Soln2(Node* head) {
    if(!head || !head->next) return head;

    vi arr;
    Node* ptr = head;
    while(ptr) {
        arr.emplace_back(ptr->data);
        ptr = ptr->next;
    }

    int n = arr.size();
    myMergeSort(arr, 0, n-1);

    ptr = head;
    int idx = 0;
    while(ptr) {
        ptr->data = arr[idx];
        idx++; ptr = ptr->next;
    }

    return head;
}

void deleteLL(Node* head);
void displayLL(Node* head);
Node* inputLL();

int main(void) {
    Node* head = inputLL();

    cout << "Orig LL: ";
    displayLL(head);

    head = sorting_Soln1(head);
    // head = sorting_Soln2(head);

    cout << "Sorted LL: ";
    displayLL(head);
    
    deleteLL(head);
    return 0;
}

// General LL helper functions.
void deleteLL(Node* head) {
    if(!head) return;

    Node* temp; int count = 0;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
        count++;
    } cout << "Deleted " << count << " nodes!\n";
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

    Node* temp = new Node(-1);
    Node* ptr = temp;
    int ele;

    for(int i=0; i<n; i++) {
        cin >> ele;
        ptr->next = new Node(ele);
        ptr = ptr->next;
    }

    Node* realHead = temp->next;
    delete temp;
    return realHead;
}
// ~() General LL helper functions.

// Merge sort .. just for reference & practise.
void myMerge(vi& arr, int left, int mid, int right) {
    int n1 = mid+1 - left;
    int n2 = right - mid;

    // Temp arrays.
    vi lHalf (n1), rHalf (n2);

    // Copying the data to temp-arrs from the orig array.
    for(int i=0; i<n1; i++) { lHalf[i] = arr[left + i]; }
    for(int i=0; i<n2; i++) { rHalf[i] = arr[mid+1 + i]; }

    // Comparing and merging the temps back into the orig.
    int i=0, j=0, k=left;
    while(i<n1 && j<n2) {
        if(lHalf[i] <= rHalf[j]) {
            arr[k++] = lHalf[i++];
            // k++; i++;
        }
        else {
            arr[k++] = rHalf[j++];
        }
    }

    while(i<n1) {   arr[k++] = lHalf[i++];  }
    while(j<n2) {   arr[k++] = rHalf[j++];  }
}

void myMergeSort(vi& arr, int left, int right) {
    if(left >= right) return;

    int mid = left + (right-left)/2;
    myMergeSort(arr, left, mid);
    myMergeSort(arr, mid+1, right);

    myMerge(arr, left, mid, right);
}
