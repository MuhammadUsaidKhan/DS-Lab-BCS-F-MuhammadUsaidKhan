#include <iostream>
#include <list>
#include <string>
using namespace std;
struct KeyValue {
    string key;
    string value;
    KeyValue(string k, string v) : key(k), value(v) {}
};
class Hash {
private:
    list<KeyValue>* table;  
    int tableSize;
    int hashFunction(string key) {
        int sum = 0;
        for (char ch : key) {
            sum += (int)ch;
        }
        return sum % tableSize;
    }
public:
    Hash(int size = 10) {
        tableSize = size;
        table = new list<KeyValue>[tableSize];
    }
    ~Hash() {
        delete[] table;
    }
    void insert(string key, string value) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                kv.value = value;
                cout << "Updated: Key '" << key << "' with value '" << value << "' at index " << index << endl;
                return;
            }
        }
        table[index].push_back(KeyValue(key, value));
        cout << "Inserted: Key '" << key << "' with value '" << value << "' at index " << index << endl;
    }
    string search(string key) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.key == key) {
                return kv.value;
            }
        }
        return "";  
    }
    bool deleteKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                cout << "Deleted: Key '" << key << "' from index " << index << endl;
                return true;
            }
        }
        cout << "Error: Key '" << key << "' not found!" << endl;
        return false;
    }
    void display() {
        cout << "\n========== HASH TABLE ==========\n";
        bool isEmpty = true;
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                isEmpty = false;
                cout << "Index " << i << ": ";
                for (auto& kv : table[i]) {
                    cout << "[" << kv.key << ": " << kv.value << "] ";
                }
                cout << endl;
            }
        }
        if (isEmpty) {
            cout << "Hash table is empty!" << endl;
        }
        cout << "================================\n" << endl;
    }
    void displayCompact() {
        cout << "\n========== HASH TABLE ==========\n";
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            if (!table[i].empty()) {
                for (auto& kv : table[i]) {
                    cout << "index " << i << ": (" << kv.key << ", " << kv.value << ")" << endl;
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << "Hash table is empty!" << endl;
        }
        cout << "================================\n" << endl;
    }
    double loadFactor() {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            count += table[i].size();
        }
        return (double)count / tableSize;
    }
    int size() {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            count += table[i].size();
        }
        return count;
    }
};
void displayMenu() {
    cout << "\n===== HASH TABLE OPERATIONS =====\n";
    cout << "1. Insert\n";
    cout << "2. Search\n";
    cout << "3. Delete\n";
    cout << "4. Display\n";
    cout << "5. Display Statistics\n";
    cout << "6. Exit\n";
    cout << "=================================\n";
    cout << "Enter your choice: ";
}
int main() {
    Hash hashTable(10);
    cout << "===== Demonstrating Hash Table Operations =====\n" << endl;
    hashTable.insert("A", "Apple");
    hashTable.insert("B", "Banana");
    hashTable.insert("C", "Cherry");
    hashTable.insert("D", "Date");
    hashTable.insert("AB", "FASTNU");
    hashTable.insert("CD", "CS");
    hashTable.display();
    cout << "\n----- Search Operations -----" << endl;
    string result = hashTable.search("AB");
    if (!result.empty()) {
        cout << "search key AB: " << result << endl;
    } else {
        cout << "Key 'AB' not found!" << endl;
    }
    result = hashTable.search("B");
    if (!result.empty()) {
        cout << "search key B: " << result << endl;
    } else {
        cout << "Key 'B' not found!" << endl;
    }
    cout << "\n----- Delete Operation -----" << endl;
    hashTable.deleteKey("C");
    hashTable.displayCompact();
    int choice;
    string key, value;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, value);
                hashTable.insert(key, value);
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                result = hashTable.search(key);
                if (!result.empty()) {
                    cout << "search key " << key << ": " << result << endl;
                } else {
                    cout << "Key '" << key << "' not found!" << endl;
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                hashTable.deleteKey(key);
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                cout << "\n----- Hash Table Statistics -----" << endl;
                cout << "Total elements: " << hashTable.size() << endl;
                cout << "Load factor: " << hashTable.loadFactor() << endl;
                cout << "---------------------------------\n" << endl;
                break;
            case 6:
                cout << "Exiting... Thank you!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
