
// 080225
// LL P1 : Searching for an element in LL.

#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

    public:
        Node(int val = 0, Node* next = nullptr) {
            this->val = val;        
            this->next = next;            
        };
};

int inputLL(Node* head);
void displayLL(Node* head);
void clearLL(Node* head);
int searchLL(Node* head, int key);

int main(void)
{
    Node* head = new Node();
    int length = inputLL(head);
    // cout << "Inputted " << length << " nodes!" << endl;
    
    cout << "LL : ";
    displayLL(head);

    int key; 
    // cout << "\nEnter key element to search : ";
    cin >> key;
    cout << "\nKey element to search : " << key << "\n";

    int keyFound = searchLL(head, key);
    if(keyFound>=0){
        cout << "\nKey \'" << key << "\' present at Position : " << keyFound << ".\n";
    }
    else {
        cout << "\nKey \'" << key << "\' is NOT present in the list!\n";
    }

    clearLL(head);
    cout << "\nCleared all the nodes.\n";
    return 0;
}

int searchLL(Node* head, int key)
{
    if(head == nullptr) 
        return -1;

    Node* ptr = head;
    int index = 0;
    while(ptr != nullptr)
    {
        if(ptr->val == key)
            return index;
        ptr = ptr->next;
        index++;
    }
    return -1;
}

int inputLL(Node* head) 
{
    int n;
    cin >> n;

    int ele, len=0;
    cin >> ele;
    head->val = ele;
    len++; n--;
    
    Node* ptr = head;

    while(n > 0) {
        cin >> ele;
        Node* newNode = new Node(ele);
        ptr->next = newNode;
        ptr = newNode;
        len++;
        n--;
        // cin >> ele;
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
        cout << ptr->val << " -> ";
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