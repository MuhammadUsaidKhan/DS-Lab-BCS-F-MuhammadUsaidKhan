#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList(int N) {
        head = new Node(1);
        Node* last = head;
        for (int i = 2; i <= N; i++) {
            Node* temp = new Node(i);
            last->next = temp;
            last = temp;
        }
        last->next = head;
    }
    int getJosephusPosition(int k) {
        Node* p = head;
        while (p->next != p) {
            for (int count = 1; count < k - 1; count++) {
                p = p->next;
            }
            Node* toDelete = p->next;
            p->next = toDelete->next;
            if (toDelete == head){
                head = toDelete->next;
            }
            delete toDelete;
            p = p->next;
        }
        return p->data;
    }
};

int main() {
    int N = 7;
    int k = 3;
    CircularLinkedList circle(N);
    int survivor = circle.getJosephusPosition(k);
    cout << "The survivor is at position: " << survivor << endl;
    return 0;
}
