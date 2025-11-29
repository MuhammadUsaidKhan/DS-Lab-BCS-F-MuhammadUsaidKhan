#include <iostream>
#include <cstring>
using namespace std;
struct Node {
    char* key;
    char* value;
    Node* next;
    Node(const char* k, const char* v) {
        key = new char[strlen(k) + 1];
        value = new char[strlen(v) + 1];
        strcpy(key, k);
        strcpy(value, v);
        next = nullptr;
    }
    ~Node() {
        delete[] key;
        delete[] value;
    }
};
class Dictionary {
private:
    Node** table;
    int tableSize;
    int hashFunction(const char* word) {
        int sum = 0;
        for (int i = 0; word[i] != '\0'; i++) {
            sum += (int)word[i];
        }
        return sum % tableSize;
    }
public:
    Dictionary() {
        tableSize = 100;
        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }
    ~Dictionary() {
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
    void Add_Record() {
        char key[100], value[100];
        cout << "Enter key (word): ";
        cin >> key;
        cout << "Enter value (meaning): ";
        cin.ignore(); 
        cin.getline(value, 100);
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                delete[] curr->value;
                curr->value = new char[strlen(value) + 1];
                strcpy(curr->value, value);
                cout << "Key '" << key << "' updated successfully at index " << index << "!" << endl;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Key '" << key << "' added successfully at index " << index << "!" << endl;
    }
    void Word_Search() {
        char key[100];
        cout << "Enter key to search: ";
        cin >> key; 
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                cout << "search key " << key << ": " << curr->value << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Error: Key '" << key << "' not found in dictionary!" << endl;
    }
    void Delete_Record() {
        char key[100];
        cout << "Enter key to delete: ";
        cin >> key;
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Error: Key '" << key << "' not found in dictionary!" << endl;
    }
    void Print_Dictionary() {
        cout << "\n========== DICTIONARY ==========\n";
        bool isEmpty = true;
        for (int i = 0; i < tableSize; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                isEmpty = false;
                cout << "index " << i << ": (" << curr->key << ", " << curr->value << ")" << endl;
                curr = curr->next;
            }
        }
        if (isEmpty) {
            cout << "Dictionary is empty!" << endl;
        }
        cout << "================================\n" << endl;
    }
    void Add_Record(const char* key, const char* value) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                delete[] curr->value;
                curr->value = new char[strlen(value) + 1];
                strcpy(curr->value, value);
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }
    void Word_Search(const char* key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                cout << "search key " << key << ": " << curr->value << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Error: Key '" << key << "' not found in dictionary!" << endl;
    }
    void Delete_Record(const char* key) {
        int index = hashFunction(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "key " << key << " deleted successfully !" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Error: Key '" << key << "' not found in dictionary!" << endl;
    }
};
void displayMenu() {
    cout << "\n===== ASCII DICTIONARY APP =====\n";
    cout << "1. Add Record\n";
    cout << "2. Search Word\n";
    cout << "3. Delete Record\n";
    cout << "4. Print Dictionary\n";
    cout << "5. Exit\n";
    cout << "================================\n";
    cout << "Enter your choice: ";
}~
int main() {
    Dictionary dict;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "Engineering");
    cout << "Sample dictionary created with test data.\n";
    cout << "\n--- Demonstrating Operations ---\n" << endl;
    dict.Word_Search("AB");
    dict.Delete_Record("EF");
    dict.Print_Dictionary();
    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                dict.Add_Record();
                break;
            case 2:
                dict.Word_Search();
                break;
            case 3:
                dict.Delete_Record();
                break;
            case 4:
                dict.Print_Dictionary();
                break;
            case 5:
                cout << "Exiting... Thank you for using Dictionary App!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
