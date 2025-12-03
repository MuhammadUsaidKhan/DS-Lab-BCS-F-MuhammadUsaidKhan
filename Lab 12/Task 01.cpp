#include <iostream>
using namespace std;
int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
void bruteForceSearch(const char* text, const char* pattern, int* results, int& count) {
    int textLen = getLength(text);
    int patternLen = getLength(pattern);
    count = 0;
    if (patternLen > textLen) {
        return;
    }
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            results[count] = i;
            count++;
        }
    }
}
void displayResults(int* results, int count) {
    cout << "[";
    for (int i = 0; i < count; i++) {
        cout << results[i];
        if (i < count - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    const char* text = "the quick brown fox jumps over the lazy dog";
    const char* pattern = "the";
    int maxMatches = getLength(text);
    int* results = new int[maxMatches];
    int count = 0;
    cout << "Text: \"" << text << "\"" << endl;
    cout << "Pattern: \"" << pattern << "\"" <<endl;
    cout << "Output: ";
    bruteForceSearch(text, pattern, results, count);
    displayResults(results, count);
    delete[] results;
    return 0;
}
