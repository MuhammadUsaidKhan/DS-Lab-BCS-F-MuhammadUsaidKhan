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
class HashTable {
private:
    Node** buckets;
    int numBuckets;
    int hashFunction(const char* str) {
        int sum = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            sum += (int)str[i];
        }
        return sum % numBuckets;
    }
public:
    HashTable(int size = 10) {
        numBuckets = size;
        buckets = new Node*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = nullptr;
        }
    }
    ~HashTable() {
        for (int i = 0; i < numBuckets; i++) {
            Node* curr = buckets[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        delete[] buckets;
    }
    void insert(const char* key, const char* value) {
        int index = hashFunction(key);
        Node* curr = buckets[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                delete[] curr->value;
                curr->value = new char[strlen(value) + 1];
                strcpy(curr->value, value);
                cout << "Updated: Key '" << key << "' = '" << value << "'" << endl;
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
        cout << "Inserted: Key '" << key << "' = '" << value << "' (Hash: " << index << ")" << endl;
    }
    char* search(const char* key) {
        int index = hashFunction(key);
        Node* curr = buckets[index];
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                return curr->value;
            }
            curr = curr->next;
        }
        return nullptr;
    }
    void remove(const char* key) {
        int index = hashFunction(key);
        Node* curr = buckets[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (strcmp(curr->key, key) == 0) {
                if (prev == nullptr) {
                    buckets[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Removed: Key '" << key << "'" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Key '" << key << "' not found!" << endl;
    }
    void display() {
        cout << "\n=== Hash Table Contents ===" << endl;
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = buckets[i];
            if (curr == nullptr) {
                cout << "Empty";
            } else {
                while (curr != nullptr) {
                    cout << "[" << curr->key << ": " << curr->value << "]";
                    if (curr->next != nullptr) {
                        cout << " -> ";
                    }
                    curr = curr->next;
                }
            }
            cout << endl;
        }
        cout << "========================\n" << endl;
    }
};

int main() {
    HashTable myhash(10);
    cout << "Performing operations:\n" << endl;
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz"); 
    myhash.display();
    cout << "Searching for key 'A': " << myhash.search("A") << endl;
    cout << "Searching for key 'B': " << myhash.search("B") << endl;
    cout << "\nRemoving key 'B':" << endl;
    myhash.remove("B");
    myhash.display();
    return 0;
}
