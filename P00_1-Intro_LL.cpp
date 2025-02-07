
// 070225
// P00_1 : Intro to Singly Linked Lists.

/*
    * Array -> LL conversion.
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data = 0, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
};

// Converting Array to LL.
Node* cnvtArrToLL(vector<int>& arr);

// LinkedList Functions.
void displayLL(Node * head);
void clearLL(Node * head);

// Array Functions.
void inputArray(vector<int>& arr);
void displayArray(vector<int>& arr);

int main(void) 
{  
    vector<int> arr;
    inputArray(arr);

    cout << "Input Array : ";
    displayArray(arr);

    Node* list = cnvtArrToLL(arr);

    cout << "Linked List : ";
    displayLL(list);
    clearLL(list);
    
    return 0;
}

// Function : Array -> LL.
Node* cnvtArrToLL(vector<int>& arr)
{
    int n = arr.size();
    if(n < 1) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* ptr = head;
    for(int i = 1; i<n; i++) {
        Node* newNode = new Node(arr[i]);
        ptr->next = newNode;
        ptr = newNode;
    }

    return head;
}

// Linked List Functions.
void displayLL(Node * head) 
{
    if(head == nullptr) {
        cout << "EMPTY List!\n";
        return;
    }
    Node * ptr = head;
    while(ptr != nullptr) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }  
    cout << "|\n";
}

void clearLL(Node * head) 
{
    if(head == nullptr) {
        return;
    }

    Node * ptr = head;
    Node * temp = nullptr;
    int count = 0;
    while(ptr != nullptr) {
        temp = ptr->next;
        delete ptr;
        count++;
        ptr = temp;
    }
    cout << "Deleted " << count << " nodes of the LL!";
    return;
}


// Array Functions.
void inputArray(vector<int>& arr) 
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    int temp;
    cout << "Enter the " << n << " array elements : ";
    for(int i=0; i<n; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }
}

void displayArray(vector<int>& arr) 
{
    cout << "[ ";
    for(const int& ele : arr) {
        cout << ele << " ";
    } cout << "]\n";
}

/*
    Node x = Node(2, nullptr);
    Node * y = &x;

    // .. is same as 
    Node* y = new Node(2, nullptr);
*/