#include <iostream>
using namespace std;
struct Pair {
    int first;
    int second;
    Pair() : first(-1), second(-1) {}
    Pair(int f, int s) : first(f), second(s) {}
};
class HashTable {
private:
    struct Node {
        int sum;
        Pair indices;
        Node* next;
        Node(int s, Pair p) : sum(s), indices(p), next(nullptr) {}
    };
    Node** table;
    int tableSize;
    int hashFunction(int key) {
        return (key % tableSize + tableSize) % tableSize;  
    }   
public:
    HashTable(int size = 1000) {
        tableSize = size;
        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }
    ~HashTable() {
        for (int i = 0; i < tableSize; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] table;
    }
    void insert(int sum, Pair indices) {
        int index = hashFunction(sum);
        Node* newNode = new Node(sum, indices);
        newNode->next = table[index];
        table[index] = newNode;
    }
    bool search(int sum, Pair& result) {
        int index = hashFunction(sum);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->sum == sum) {
                result = curr->indices;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};
bool findPairsWithEqualSum(int arr[], int n) {
    HashTable hashTable;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            Pair existingPair;
            if (hashTable.search(sum, existingPair)) {
                int a = arr[existingPair.first];
                int b = arr[existingPair.second];
                int c = arr[i];
                int d = arr[j];
                if (a != c && a != d && b != c && b != d) {
                    cout << "Output: (" << a << ", " << b << ") and (" 
                         << c << ", " << d << ")" << endl;
                    cout << "Explanation: " << a << "+" << b << " = " 
                         << c << "+" << d << " = " << sum << endl;
                    return true;
                }
            }
            hashTable.insert(sum, Pair(i, j));
        }
    }
    cout << "Output: No pairs found" << endl;
    return false;
}
void printArray(int arr[], int n) {
    cout << "Input: {";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "}" << endl;
}
int main() {
    cout << "Test Case 1:" << endl;
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printArray(arr1, n1);
    findPairsWithEqualSum(arr1, n1);
    cout << "\n" << endl;
    cout << "Test Case 2:" << endl;
    int arr2[] = {3, 4, 7, 1, 12, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, n2);
    findPairsWithEqualSum(arr2, n2);
    cout << "\n" << endl;
    cout << "Test Case 3:" << endl;
    int arr3[] = {65, 30, 7, 90, 1, 9, 8};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printArray(arr3, n3);
    findPairsWithEqualSum(arr3, n3);
    cout << "\n" << endl;
    cout << "Test Case 4:" << endl;
    int arr4[] = {10, 20, 30, 40, 50};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    printArray(arr4, n4);
    findPairsWithEqualSum(arr4, n4);
    cout << "\n" << endl;
    cout << "===== Interactive Mode =====" << endl;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " distinct integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "\n";
    printArray(arr, n);
    findPairsWithEqualSum(arr, n);
    delete[] arr;
    return 0;
}
