#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    public:
        // Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
        Node(int data = 0, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
        // Other methods as required.
};

// Commonly needed LL Functions.
int inputLL(Node** head);
void displayLL(Node* head);
void clearLL(Node* head);

int main(void) {
    Node* head = new Node();
    int length = inputLL(&head);
    cout << "\nInputted " << length << " nodes!" << endl;
    
    cout << "LL : ";
    displayLL(head);

    // Core Code for the operation.

    clearLL(head);
    cout << "\nCleared all the nodes.\n";
    return 0;
}


int inputLL(Node** head) 
{
    int len = 0;
    cout << "Enter elements of LL (-1 to stop entering..) : ";
    int ele;
    cin >> ele;
    
    if(ele == -1){
        (*head) = nullptr;
        return 0;
    }   

    (*head)->data = ele;
    len++;
    
    Node* ptr = (*head);

    cin >> ele;
    while(ele != -1) 
    {
        Node* newNode = new Node(ele);
        ptr->next = newNode;
        ptr = newNode;
        len++;
        cin >> ele;
    }
    // cout << "Inputted " << len << " nodes!" << endl;
    return len;
}

void displayLL(Node* head) {
    if(head == nullptr)
    {
        cout << "EMPTY List!\n";
        return;
    }
    Node* ptr = head;

    while(ptr != nullptr) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "|\n";
}

void clearLL(Node* head) {
    if(head == nullptr)
        return;

    Node* ptr = head;
    Node* temp = nullptr;

    while(ptr != nullptr) {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    return;
}