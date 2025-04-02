
// 020425
/*
    Modular Node.

    * Given is a singly linked list of 'N' nodes, where every node has the structure : 
    * Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

    * Find out the last node in the linked list such that 'x % K' = 0, where 'x' is the position of the node from the beginning.
    * Return the last node that satisfies the above property.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            this->next = NULL;
        }
        ~Node() {
            if(next != NULL) {
                delete next;
            }
        }
};

class Solution {
    public:
        Node* modularNode(int k, Node* head)
        {
            int count = 1;
            Node* target;
            Node* ptr = head;

            if(count%k == 0){
                target = ptr;
            }
            ptr = ptr->next;
            while(ptr->next != NULL) {
                count++;
                if(count % k == 0) {
                    target = ptr;
                }
                ptr = ptr->next;
            }
        return target;
        }
};

int main(void) {
    int n;
    cout << "Enter LinkedList size : ";
    cin >> n;

    vector<int> temp (n);
    cout << "Enter the " << n << " nodes : ";
    for(int i=0; i<n; i++) {
        cin >> temp[i];
    }

    Node * head = new Node(temp[0]);
    Node * ptr = head;
    for(int i=1; i<n; i++){
        ptr->next = new Node(temp[i]);
        ptr = ptr->next;
    }

    int k;
    cout << "Enter \'k\' : ";
    cin >> k;
    
    Node * lastModularNode = Solution().modularNode(k, head);
    cout << "Last Modular Node Value : " << lastModularNode->data << endl;
    
    return 0;
}