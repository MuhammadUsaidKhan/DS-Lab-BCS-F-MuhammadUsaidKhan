#include <iostream>
#include <cstring>
using namespace std;
struct Student {
    int rollNumber;
    char name[100];
    bool isOccupied;
    bool isDeleted;
    Student() : rollNumber(-1), isOccupied(false), isDeleted(false) {
        name[0] = '\0';
    }
};
class StudentHashTable {
private:
    Student* table;
    int tableSize;
    int hashFunction(int rollNumber) {
        return rollNumber % tableSize;
    }
public:
    StudentHashTable() {
        tableSize = 15;
        table = new Student[tableSize];
    }
    ~StudentHashTable() {
        delete[] table;
    }
    bool InsertRecord(int rollNumber, const char* name) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        while (attempt < tableSize) {
            int probeIndex = (index + attempt * attempt) % tableSize;
            if (!table[probeIndex].isOccupied || table[probeIndex].isDeleted) {
                table[probeIndex].rollNumber = rollNumber;
                strcpy(table[probeIndex].name, name);
                table[probeIndex].isOccupied = true;
                table[probeIndex].isDeleted = false;
                cout << "Record inserted successfully!" << endl;
                cout << "Roll Number: " << rollNumber << ", Name: " << name 
                     << " at index " << probeIndex << endl;
                return true;
            }
            if (table[probeIndex].rollNumber == rollNumber && 
                table[probeIndex].isOccupied && !table[probeIndex].isDeleted) {
                strcpy(table[probeIndex].name, name);
                cout << "Record updated successfully!" << endl;
                cout << "Roll Number: " << rollNumber << ", Name: " << name 
                     << " at index " << probeIndex << endl;
                return true;
            }
            attempt++;
        }
        cout << "Hash table is full! Cannot insert record." << endl;
        return false;
    }
    bool SearchRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        while (attempt < tableSize) {
            int probeIndex = (index + attempt * attempt) % tableSize;
            if (!table[probeIndex].isOccupied) {
                cout << "Record not found" << endl;
                return false;
            }
            if (table[probeIndex].rollNumber == rollNumber && 
                table[probeIndex].isOccupied && !table[probeIndex].isDeleted) {
                cout << "Record found!" << endl;
                cout << "Roll Number: " << rollNumber 
                     << ", Name: " << table[probeIndex].name 
                     << " at index " << probeIndex << endl;
                return true;
            }
            attempt++;
        }
        cout << "Record not found" << endl;
        return false;
    }
    bool DeleteRecord(int rollNumber) {
        int index = hashFunction(rollNumber);
        int attempt = 0;
        while (attempt < tableSize) {
            int probeIndex = (index + attempt * attempt) % tableSize;
            if (!table[probeIndex].isOccupied) {
                cout << "Record not found for deletion" << endl;
                return false;
            }
            if (table[probeIndex].rollNumber == rollNumber && 
                table[probeIndex].isOccupied && !table[probeIndex].isDeleted) {
                table[probeIndex].isDeleted = true;
                cout << "Record deleted successfully!" << endl;
                cout << "Roll Number: " << rollNumber << " at index " << probeIndex << endl;
                return true;
            }
            attempt++;
        }
        cout << "Record not found for deletion" << endl;
        return false;
    }
    void DisplayTable() {
        cout << "\n========== HASH TABLE ==========\n";
        cout << "Table Size: " << tableSize << "\n" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            if (table[i].isOccupied && !table[i].isDeleted) {
                cout << "[Roll: " << table[i].rollNumber 
                     << ", Name: " << table[i].name << "]";
            } else if (table[i].isDeleted) {
                cout << "[DELETED]";
            } else {
                cout << "[EMPTY]";
            }
            cout << endl;
        }
        cout << "================================\n" << endl;
    }
    double getLoadFactor() {
        int count = 0;
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied && !table[i].isDeleted) {
                count++;
            }
        }
        return (double)count / tableSize;
    }
    void DisplayStatistics() {
        int occupied = 0;
        int deleted = 0;
        int empty = 0;
        for (int i = 0; i < tableSize; i++) {
            if (table[i].isOccupied && !table[i].isDeleted) {
                occupied++;
            } else if (table[i].isDeleted) {
                deleted++;
            } else {
                empty++;
            }
        }
        cout << "\n----- Hash Table Statistics -----" << endl;
        cout << "Table Size: " << tableSize << endl;
        cout << "Occupied Slots: " << occupied << endl;
        cout << "Deleted Slots: " << deleted << endl;
        cout << "Empty Slots: " << empty << endl;
        cout << "Load Factor: " << getLoadFactor() << endl;
        cout << "---------------------------------\n" << endl;
    }
};
void displayMenu() {
    cout << "\n===== STUDENT HASH TABLE =====\n";
    cout << "1. Insert Record\n";
    cout << "2. Search Record\n";
    cout << "3. Delete Record\n";
    cout << "4. Display Table\n";
    cout << "5. Display Statistics\n";
    cout << "6. Exit\n";
    cout << "==============================\n";
    cout << "Enter your choice: ";
}
int main() {
    StudentHashTable hashTable;
    cout << "===== Demonstrating Quadratic Probing =====\n" << endl;
    hashTable.InsertRecord(101, "Ali Khurram");
    hashTable.InsertRecord(116, "Obaidullah");      
    hashTable.InsertRecord(131, "Muhammad Ibrahim");  
    hashTable.InsertRecord(102, "Muhammad Hasnain Siddiqui Nazeer");
    hashTable.InsertRecord(117, "Yousha Faisal Battiwala");
    hashTable.InsertRecord(103, "Jawwad Ahmad Chandio");
    cout << "\n";
    hashTable.DisplayTable();
    cout << "\n----- Search Operations -----\n" << endl;
    hashTable.SearchRecord(101);
    cout << endl;
    hashTable.SearchRecord(131);
    cout << endl;
    hashTable.SearchRecord(999);  
    cout << "\n----- Delete Operation -----\n" << endl;
    hashTable.DeleteRecord(102);
    cout << "\n";
    hashTable.DisplayTable();
    cout << "\n----- Insert After Deletion -----\n" << endl;
    hashTable.InsertRecord(150, "Syed Ali Sufyaan");
    cout << "\n";
    hashTable.DisplayTable();
    hashTable.DisplayStatistics();
    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                int rollNumber;
                char name[100];
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                cout << "Enter Name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << endl;
                hashTable.InsertRecord(rollNumber, name);
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number to search: ";
                cin >> rollNumber;
                cout << endl;
                hashTable.SearchRecord(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                cout << endl;
                hashTable.DeleteRecord(rollNumber);
                break;
            }
            case 4:
                hashTable.DisplayTable();
                break;
            case 5:
                hashTable.DisplayStatistics();
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
