#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

        // Other methods as required.
        Node* deleteHead(Node* head);
        Node* deleteTail(Node* head);
        Node* deleteBasedOnIndex(Node* head, int index);
        Node* deleteBasedOnValue(Node* head, int val, bool * isDeleted);
};

// CORE Functions.
Node* Node :: deleteHead(Node* head) 
{
    if(head == nullptr) 
        return nullptr;

    Node* newHead = head->next;
    delete head;
    return newHead;
}

Node* Node :: deleteTail(Node* head) 
{
    if(!head) return head;

    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    
    Node* ptr = head;

    // Traverse to the node, just before the Tail.
    while(ptr->next->next != nullptr) {
        ptr = ptr->next;
    }

    Node* tailNode = ptr->next;
    delete tailNode;
    ptr->next = nullptr;
    return head;
}

Node* Node :: deleteBasedOnIndex(Node* head, int index) {
    if(head == nullptr)
        return nullptr;
    
    if(index == 0)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    Node* ptr = head;
    int i=0;
    while(i < index-1) {
        ptr = ptr->next;
        if(ptr->next == nullptr)
        {
            cout << "Index out of bounds." << endl;
            return head;
        }
        i++;
    }

    Node* temp = ptr->next;
    ptr->next = ptr->next->next;
    delete temp;
    return head;
}

Node* Node :: deleteBasedOnValue(Node* head, int val, bool * isDeleted)
{
    if(head == nullptr)
        return head;

    
    if(head->data == val)
    {
        Node* temp = head->next;
        delete head;
        *isDeleted = true;
        return temp;
    }

    Node* ptr = head;
    while(ptr->next != NULL) {
        if(ptr->next->data == val) {
            Node* temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
            *isDeleted = true;
            return head;
        }
    }
    return head;
}

// Commonly needed LL Functions.
int inputLL(Node** head);
void displayLL(Node* head);
void clearLL(Node* head);
int menu();

int main(void) {
    Node* head = new Node();
    int length = inputLL(&head);
    // cout << "\nInputted " << length << " nodes!" << endl;
    
    cout << "\nOrig LL : ";
    displayLL(head);

    // Core Code for the operation.
    int ch;
    bool bExit = false;
    while(!bExit) {
        ch = menu();
        switch(ch){
            case 1:
                cout << "Delete-HEAD initiated..\n";
                head = head->deleteHead(head);     
            break;
            case 2:
                cout << "Delete-TAIL initiated..\n";
                head = head->deleteTail(head);     
            break;
            case 3:
                cout << "Delete-INDEX initiated..\n";
            
                int index;
                cout << "Enter the index to delete : ";
                cin >> index;
                head = head->deleteBasedOnIndex(head, index);
            break;
            case 4:
                cout << "Delete-VALUE initiated..\n";
                bool isDeleted;
                int val; 
                cout << "Enter the value to delete : ";
                head = head->deleteBasedOnValue(head, val, &isDeleted);
                if(isDeleted){
                    cout << "Node deleted.\n";
                }     
                else {cout << "Node-VALUE not found.\n";}
            break;
            case 0:
                clearLL(head);
                cout << "Exiting the interface ... ";
                bExit = true;
            break;
            
            default: 
                cout << "Invalid choice .. try again" << endl;
        }
    }
    
    cout << "\nLL ( after deleteTail() ): ";
    displayLL(head);

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
    while(ele != -1) {
        Node* newNode = new Node(ele);
        ptr->next = newNode;
        ptr = newNode;
        len++;
        cin >> ele;
    }
    cout << "Inputted " << len << " nodes!" << endl;
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

int menu() {
    cout << "\nEnter accordingly : " << endl;
    cout << "\t\'1\' - Delete-Head. \t\t\t  \'2\' - Delete-Tail." << endl;
    cout << "\t\'3\' - Delete-Based-On-INDEX (0 - based)";
    cout << "\t  \'4\' - Delete-Based-On-VALUE " << endl;
    cout << "\t\'0\' - EXIT" << endl;;
    cout << "Your choice : ";
    int ch; cin >> ch;
    return ch;
}