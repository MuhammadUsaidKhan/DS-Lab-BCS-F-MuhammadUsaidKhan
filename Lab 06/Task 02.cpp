#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* next;
};
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(string value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (isEmpty()) {
            cout << "No previous page to go back to!" << endl;
        } else {
            cout << "Going back from: " << top->data << endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void peek() {
        if (isEmpty()) {
            cout << "No current page." << endl;
        } else {
            cout << "Current page: " << top->data << endl;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "No browsing history." << endl;
        } else {
            cout << "\nBrowsing History (Most recent first):" << endl;
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};
int main() {
    Stack history;
    int choice;
    string page;
    do {
        cout << "\n--- Browser History Menu ---\n";
        cout << "1. Visit new page\n";
        cout << "2. Go back\n";
        cout << "3. Current page\n";
        cout << "4. Show history\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter page URL: ";
                getline(cin, page);
                history.push(page);
                break;
            case 2:
                history.pop();
                break;
            case 3:
                history.peek();
                break;
            case 4:
                history.display();
                break;
            case 5:
                cout << "Exiting browser..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
