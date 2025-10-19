#include <iostream>
#include <string>
using namespace std;
struct Process {
    int id;
    int priority;  
};
class Queue {
private:
    Process arr[50];
    int front, rear;
public:
    Queue() {
        front = rear = -1;
    }
    bool isFull() {
        return (rear + 1) % 50 == front;
    }
    bool isEmpty() {
        return front == -1;
    }
    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot add process " << p.id << endl;
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % 50;
        arr[rear] = p;
    }
    Process dequeue() {
        Process temp;
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            temp.id = -1;
            return temp;
        }
        temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % 50;
        return temp;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "\nProcesses in Queue (Arrival Order):\n";
        int i = front;
        while (true) {
            cout << "  ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
            if (i == rear) break;
            i = (i + 1) % 50;
        }
    }
};
class Stack {
private:
    Process arr[50];
    int top;
public:
    Stack() { top = -1; }
    bool isFull() {
        return top == 49;
    }
    bool isEmpty() {
        return top == -1;
    }
    void push(Process p) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = p;
    }
    Process pop() {
        Process temp;
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            temp.id = -1;
            return temp;
        }
        return arr[top--];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "\nProcesses in Stack (Execution Order):\n";
        for (int i = top; i >= 0; i--) {
            cout << "  ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
        }
    }
};
int main() {
    Queue arrivalQueue;
    Stack executionStack;
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter Process ID and Priority: ";
        cin >> p.id >> p.priority;
        arrivalQueue.enqueue(p);
    }
    arrivalQueue.display();
    cout << "\nScheduling: Moving processes from Queue → Stack based on Priority...\n";)
    while (!arrivalQueue.isEmpty()) {
        int size = 0, maxPriority = -999, idx = -1;
        Process tempArr[50];
        while (!arrivalQueue.isEmpty()) {
            tempArr[size] = arrivalQueue.dequeue();
            if (tempArr[size].priority > maxPriority) {
                maxPriority = tempArr[size].priority;
                idx = size;
            }
            size++;
        }
        executionStack.push(tempArr[idx]);
        for (int i = 0; i < size; i++) {
            if (i != idx)
                arrivalQueue.enqueue(tempArr[i]);
        }
    }
    executionStack.display();
    cout << "\nExecuting processes (Stack - LIFO order):\n";
    while (!executionStack.isEmpty()) {
        Process p = executionStack.pop();
        cout << "  Executing Process ID: " << p.id << " (Priority: " << p.priority << ")\n";
    }
    cout << "\nAll processes executed.\n";
    return 0;
}
