#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* child;
    Node(int val) {
        data = val;
        next = NULL;
        child = NULL;
    }
};
Node* flatten(Node* head) {
    if (!head){
        return NULL;
    }
    Node* curr = head;
    while (curr) {
        if (curr->child) {
            Node* childHead = flatten(curr->child);  
            Node* nextNode = curr->next;
            curr->next = childHead;
            Node* temp = childHead;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = nextNode;
            curr->child = NULL;
        }
        curr = curr->next;
    }
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* child = new Node(4);
    child->next = new Node(5);
    head->next->child = child;
    cout << "Original list with child:\n";
    cout << "1 -> 2 -> 3\n      |\n      4 -> 5\n";
    Node* flatHead = flatten(head);
    cout << "\nFlattened list:\n";
    printList(flatHead);  
    return 0;
}
