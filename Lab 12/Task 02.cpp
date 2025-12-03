#include <iostream>
using namespace std;
int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
long long power(int base, int exp, int mod) {
    long long result = 1;
    long long b = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }
        b = (b * b) % mod;
        exp /= 2;
    }
    return result;
}
bool checkMatch(const char* text, const char* pattern, int start, int patternLen) {
    for (int i = 0; i < patternLen; i++) {
        if (text[start + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}
void rabinKarpSearch(const char* text, const char* pattern, int* results, int& count) {
    int textLen = getLength(text);
    int patternLen = getLength(pattern);
    count = 0;
    if (patternLen > textLen) {
        return;
    }
    const int d = 256;      
    const int q = 101;     
    long long patternHash = 0;  
    long long textHash = 0;     
    long long h = 1;            
    h = power(d, patternLen - 1, q);
    for (int i = 0; i < patternLen; i++) {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;
    }
    cout << "\n--- Hash Collision Detection ---" << endl;
    cout << "Pattern hash: " << patternHash << endl << endl;
    for (int i = 0; i <= textLen - patternLen; i++) {
        if (patternHash == textHash) {
            cout << "Hash match at position " << i << " (hash: " << textHash << ")" << endl;
            if (checkMatch(text, pattern, i, patternLen)) {
                cout << "  -> GENUINE MATCH: \"";
                for (int k = 0; k < patternLen; k++) {
                    cout << text[i + k];
                }
                cout << "\"" << endl;
                results[count] = i;
                count++;
            } else {
                cout << "  -> FALSE POSITIVE (Hash Collision): \"";
                for (int k = 0; k < patternLen; k++) {
                    cout << text[i + k];
                }
                cout << "\" != \"" << pattern << "\"" << endl;
            }
        }
        if (i < textLen - patternLen) {
            textHash = (d * (textHash - text[i] * h) + text[i + patternLen]) % q;
            if (textHash < 0) {
                textHash = (textHash + q);
            }
        }
    }
    cout << "-------------------------------\n" << endl;
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
    const char* text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    const char* pattern = "Algorithms";
    int maxMatches = getLength(text);
    int* results = new int[maxMatches];
    int count = 0;
    cout << "=== Rabin-Karp Plagiarism Detection ===" << endl;
    cout << "\nText: \"" << text << "\"" << endl;
    cout << "Pattern: \"" << pattern << "\"" << endl;
    rabinKarpSearch(text, pattern, results, count);
    cout << "Output: ";
    displayResults(results, count);
    cout << "\n--- Algorithm Details ---" << endl;
    cout << "Base (d): 256 (ASCII character set)" << endl;
    cout << "Prime modulus (q): 101" << endl;
    cout << "Pattern length: " << getLength(pattern) << endl;
    cout << "Total genuine matches found: " << count << endl;
    cout << "\n\n=== Testing Hash Collision Scenario ===" << endl;
    const char* text2 = "ABC ABCD ABCE ABCF algorithms Algorithms";
    const char* pattern2 = "Algorithms";
    int count2 = 0;
    cout << "\nText: \"" << text2 << "\"" << endl;
    cout << "Pattern: \"" << pattern2 << "\"" << endl;
    rabinKarpSearch(text2, pattern2, results, count2);
    cout << "Output: ";
    displayResults(results, count2);
    delete[] results;
    return 0;
}
