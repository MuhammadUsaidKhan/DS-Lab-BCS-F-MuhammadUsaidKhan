#include <iostream>
#include <string>
using namespace std;
class SNode {
public:
    int data;
    SNode* next;
    SNode(int val) {
        data = val;
        next = NULL;
    }
};
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
DNode* convertToDoubly(SNode* head) {
    if (!head){
        return NULL;
    }
    SNode* curr = head;
    DNode* dHead = new DNode(curr->data);
    DNode* dPrev = dHead;
    curr = curr->next;
    while (curr) {
        DNode* dNew = new DNode(curr->data);
        dPrev->next = dNew;
        dNew->prev = dPrev;
        dPrev = dNew;
        curr = curr->next;
    }
    return dHead;
}
void convertToCircular(SNode* head) {
    if (!head){
        return;
    }
    SNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head;
}
void printSingly(SNode* head) {
    SNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printDoubly(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printCircular(SNode* head, int N) {
    SNode* temp = head;
    int count = 0;
    while (temp && count < N) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

int main() {
    SNode* sHead = new SNode(10);
    sHead->next = new SNode(20);
    sHead->next->next = new SNode(30);
    sHead->next->next->next = new SNode(40);
    cout << "Original Singly Linked List: ";
    printSingly(sHead);
    DNode* dHead = convertToDoubly(sHead);
    cout << "Converted Doubly Linked List: ";
    printDoubly(dHead);
    convertToCircular(sHead);
    cout << "Converted Circular Linked List (First 8 elements): ";
    printCircular(sHead, 8);  
    return 0;
}
