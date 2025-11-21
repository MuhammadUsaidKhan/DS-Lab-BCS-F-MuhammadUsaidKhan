#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
Node* getLastNode(Node* head) {
    if (head == nullptr) return nullptr;
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* current = head;
    Node* tail = pivot;
    *newHead = nullptr;
    *newEnd = pivot;
    while (current != pivot) {
        if (current->data < pivot->data) {
            if (*newHead == nullptr) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }
    if (*newHead == nullptr) {
        *newHead = pivot;
    }
    *newEnd = tail;
    return pivot;
}
Node* quickSortRecursive(Node* head, Node* end) {
    if (head == nullptr || head == end) {
        return head;
    }
    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;
        newHead = quickSortRecursive(newHead, temp);
        temp = getLastNode(newHead);
        temp->next = pivot;
    }
    pivot->next = quickSortRecursive(pivot->next, newEnd);
    return newHead;
}
void quickSort(Node** headRef) {
    if (*headRef == nullptr || (*headRef)->next == nullptr) {
        return;
    }
    Node* end = getLastNode(*headRef);
    *headRef = quickSortRecursive(*headRef, end);
}
void append(Node** headRef, int data) {
    Node* newNode = new Node(data);
    if (*headRef == nullptr) {
        *headRef = newNode;
        return;
    }
    Node* current = *headRef;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}
void deleteList(Node** headRef) {
    Node* current = *headRef;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *headRef = nullptr;
}
Node* partitionSwap(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* current = head;
    Node* tail = pivot;
    while (current != pivot) {
        if (current->data < pivot->data) {
            if (*newHead == nullptr) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }
    if (*newHead == nullptr) {
        *newHead = pivot;
    }
    *newEnd = tail;
    return pivot;
}
void demoQuickSort() {
    cout << "=== QUICK SORT ON LINKED LIST DEMO ===" << endl;
    Node* head1 = nullptr;
    int arr1[] = {10, 7, 8, 9, 1, 5, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < n1; i++) {
        append(&head1, arr1[i]);
    }
    cout << "Original list 1: ";
    printList(head1);
    quickSort(&head1);
    cout << "Sorted list 1: ";
    printList(head1);
    cout << "Expected: 1 3 5 7 8 9 10" << endl;
    deleteList(&head1);
    cout << endl;
    Node* head2 = nullptr;
    cout << "Original list 2: ";
    printList(head2);
    quickSort(&head2);
    cout << "Sorted list 2: ";
    printList(head2);
    cout << endl;
    Node* head3 = nullptr;
    append(&head3, 5);
    cout << "Original list 3: ";
    printList(head3);
    quickSort(&head3);
    cout << "Sorted list 3: ";
    printList(head3);
    cout << endl;
    deleteList(&head3);
    Node* head4 = nullptr;
    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    for (int i = 0; i < n4; i++) {
        append(&head4, arr4[i]);
    }
    cout << "Original list 4: ";
    printList(head4);
    quickSort(&head4);
    cout << "Sorted list 4: ";
    printList(head4);
    deleteList(&head4);
    cout << endl;
    Node* head5 = nullptr;
    int arr5[] = {5, 4, 3, 2, 1};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    for (int i = 0; i < n5; i++) {
        append(&head5, arr5[i]);
    }
    cout << "Original list 5: ";
    printList(head5);
    quickSort(&head5);
    cout << "Sorted list 5: ";
    printList(head5);
    deleteList(&head5);
}
void interactiveQuickSort() {
    Node* head = nullptr;
    int n, value;
    cout << "\n=== INTERACTIVE QUICK SORT ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Invalid number of elements!" << endl;
        return;
    }
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        append(&head, value);
    }
    cout << "Original list: ";
    printList(head);
    quickSort(&head);
    cout << "Sorted list: ";
    printList(head);
    deleteList(&head);
}

int main() {
    int choice;
    do {
        cout << "\n=== QUICK SORT ON LINKED LIST ===" << endl;
        cout << "1. Run demo with test cases" << endl;
        cout << "2. Interactive mode" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                demoQuickSort();
                break;
            case 2:
                interactiveQuickSort();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);
    return 0;
}
