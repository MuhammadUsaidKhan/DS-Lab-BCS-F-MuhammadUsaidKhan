#include <iostream>
#include <string>
using namespace std;
struct Runner {
    string name;
    int finishTime;
};
void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Runner* leftArr = new Runner[n1];
    Runner* rightArr = new Runner[n2];
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].finishTime <= rightArr[j].finishTime) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void inputRunners(Runner runners[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter name and finish time for runner " << (i + 1) << ": ";
        cin >> runners[i].name >> runners[i].finishTime;
        if (runners[i].finishTime < 0) {
            cout << "Invalid finish time! Please enter a non-negative value." << endl;
            i--; 
        }
    }
}
void displayTop5(Runner runners[], int size) {
    cout << "\nTop 5 fastest runners:" << endl;
    int count = min(5, size); 
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << ". " << runners[i].name << " - " << runners[i].finishTime << " seconds" << endl;
    }
}
void displayAllRunners(Runner runners[], int size) {
    cout << "\nAll runners (sorted by finish time):" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << runners[i].name << " - " << runners[i].finishTime << " seconds" << endl;
    }
}
int main() {
    const int TOTAL_RUNNERS = 10;
    Runner runners[TOTAL_RUNNERS];
    cout << "=== MARATHON RUNNER SORTING PROGRAM ===" << endl;
    cout << "Please enter data for " << TOTAL_RUNNERS << " runners:" << endl;
    inputRunners(runners, TOTAL_RUNNERS);
    mergeSort(runners, 0, TOTAL_RUNNERS - 1);
    displayTop5(runners, TOTAL_RUNNERS);
    char choice;
    cout << "\nWould you like to see all sorted runners? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        displayAllRunners(runners, TOTAL_RUNNERS);
    }
    return 0;
}
