#include <iostream>
#include <string>
using namespace std;
struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};
void addNode(Node** head, string name, int score) {
    Node* newNode = new Node(name, score);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
int getMaxScore(Node* head) {
    int maxScore = 0;
    Node* current = head;
    while (current != nullptr) {
        if (current->score > maxScore) {
            maxScore = current->score;
        }
        current = current->next;
    }
    return maxScore;
}
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
void linkedListToArray(Node* head, string* names, int* scores) {
    Node* current = head;
    int i = 0;
    while (current != nullptr) {
        names[i] = current->name;
        scores[i] = current->score;
        current = current->next;
        i++;
    }
}
int binarySearch(string* names, int* scores, int size, string targetName, int targetScore) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (scores[mid] == targetScore && names[mid] == targetName) {
            return mid;
        }
        else if (scores[mid] < targetScore || 
                (scores[mid] == targetScore && names[mid] < targetName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
void deleteNode(Node** head, string name, int score) {
    if (*head == nullptr) return;
    if ((*head)->name == name && (*head)->score == score) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }
    Node* current = *head;
    Node* prev = nullptr;
    while (current != nullptr && !(current->name == name && current->score == score)) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) return;
    prev->next = current->next;
    delete current;
}
void radixSort(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) return;
    int maxScore = getMaxScore(*head);
    Node* buckets[10];
    Node* tails[10];
    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        for (int i = 0; i < 10; i++) {
            buckets[i] = nullptr;
            tails[i] = nullptr;
        }
        Node* current = *head;
        while (current != nullptr) {
            int digit = (current->score / exp) % 10;
            Node* nextNode = current->next;
            if (buckets[digit] == nullptr) {
                buckets[digit] = current;
                tails[digit] = current;
                tails[digit]->next = nullptr;
            } else {
                tails[digit]->next = current;
                tails[digit] = current;
                tails[digit]->next = nullptr;
            }
            current = nextNode;
        }
        *head = nullptr;
        Node* tail = nullptr;
        for (int i = 0; i < 10; i++) {
            if (buckets[i] != nullptr) {
                if (*head == nullptr) {
                    *head = buckets[i];
                    tail = tails[i];
                } else {
                    tail->next = buckets[i];
                    tail = tails[i];
                }
            }
        }
    }
}
void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->name << " " << current->score << endl;
        current = current->next;
    }
}
void deleteList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = nullptr;
}
int main() {
    Node* head = nullptr;
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);
    cout << "Sorted list by score:" << endl;
    radixSort(&head);
    displayList(head);
    string searchName;
    int searchScore;
    cout << "\nEnter student name to search and delete: ";
    cin >> searchName;
    cout << "Enter student score: ";
    cin >> searchScore;
    int size = countNodes(head);
    string* names = new string[size];
    int* scores = new int[size];
    linkedListToArray(head, names, scores);
    int index = binarySearch(names, scores, size, searchName, searchScore);
    if (index != -1) {
        cout << "Record found! Deleting: " << searchName << " " << searchScore << endl;
        deleteNode(&head, searchName, searchScore);
        cout << "\nUpdated list:" << endl;
        displayList(head);
    } else {
        cout << "Record not found. No changes made." << endl;
    }
    delete[] names;
    delete[] scores;
    deleteList(&head);
    return 0;
}
