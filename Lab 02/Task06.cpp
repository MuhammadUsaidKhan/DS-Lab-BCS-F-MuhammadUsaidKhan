#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;   

public:
    SafePointer() {
        ptr = nullptr;
    }
    SafePointer(int value) {
        ptr = new int(value);
    }
    void setValue(int value) {
        if (ptr == nullptr) {
            ptr = new int;
        }
        *ptr = value;
    }
    int getValue() {
        if (ptr == nullptr) {
            cout << "Error: Trying to access null pointer!" << endl;
            return -1; 
        }
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~SafePointer() {
        release();
    }
};

int main() {
    const int n = 5;
    SafePointer students[n];   

    int marks[n] = {85, 90, 78, 92, 88};

    for (int i = 0; i < n; i++) {
        students[i].setValue(marks[i]);
    }
    cout << "Student Marks:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << (i + 1) << ": " << students[i].getValue() << endl;
    }
    for (int i = 0; i < n; i++) {
        students[i].release();
    }
    return 0;
}
