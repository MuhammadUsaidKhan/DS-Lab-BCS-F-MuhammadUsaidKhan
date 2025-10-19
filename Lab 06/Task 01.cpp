#include <iostream>
using namespace std;
class Stack {
private:
    int top;        
    int size;      
    int *arr;       
public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            top++;
            arr[top] = value;
        }
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }
    void peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack contents: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;
    Stack st(n);
    int choice, value;
    do {
        cout << "\n--- Stack Operations Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
