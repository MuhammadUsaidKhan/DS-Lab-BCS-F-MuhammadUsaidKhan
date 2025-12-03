#include <iostream>
using namespace std;
int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
void computeLPSArray(const char* pattern, int patternLen, int* lps) {
    int length = 0;  
    lps[0] = 0;      
    int i = 1;
    while (i < patternLen) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            cout << "  " << i << "   |  " << pattern[i] << "   |   " << length 
                 << "    |     " << lps[i] << "     | Match found, increment length" << endl;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
                cout << "  " << i << "   |  " << pattern[i] << "   |   " << length 
                     << "    |     -     | Mismatch, backtrack to LPS[" << (length) << "]" << endl;
            } else {
                lps[i] = 0;
                cout << "  " << i << "   |  " << pattern[i] << "   |   " << length 
                     << "    |     " << lps[i] << "     | No match, set to 0" << endl;
                i++;
            }
        }
    }
    cout << "\nFinal LPS Array: [";
    for (int j = 0; j < patternLen; j++) {
        cout << lps[j];
        if (j < patternLen - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "\nLPS Array Meaning:" << endl;
    for (int j = 0; j < patternLen; j++) {
        cout << "  LPS[" << j << "] = " << lps[j] << " -> ";
        if (lps[j] == 0) {
            cout << "No proper prefix-suffix match" << endl;
        } else {
            cout << "Longest prefix \"";
            for (int k = 0; k < lps[j]; k++) {
                cout << pattern[k];
            }
            cout << "\" equals suffix ending at position " << j << endl;
        }
    }
}
void KMPSearch(const char* text, const char* pattern, int* results, int& count) {
    int textLen = getLength(text);
    int patternLen = getLength(pattern);
    count = 0;
    if (patternLen > textLen) {
        return;
    }
    int* lps = new int[patternLen];
    computeLPSArray(pattern, patternLen, lps);
    int i = 0;  
    int j = 0;  
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            cout << "    " << i << "      |      " << j 
                 << "        | Match: '" << text[i] << "'" << endl;
            i++;
            j++;
        }
        if (j == patternLen) {
            int matchPos = i - j;
            cout << "    -      |      -        | ** PATTERN FOUND at position " 
                 << matchPos << " **" << endl;
            results[count] = matchPos;
            count++;
            j = lps[j - 1];  
            if (j > 0) {
                cout << "    -      |      -        | Continue from pattern index " 
                     << j << " (using LPS)" << endl;
            }
        } else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                cout << "    " << i << "      |      " << j 
                     << "        | Mismatch: '" << text[i] << "' != '" << pattern[j] 
                     << "', shift using LPS[" << (j-1) << "]=" << lps[j-1] << endl;
                j = lps[j - 1];
            } else {
                cout << "    " << i << "      |      " << j 
                     << "        | Mismatch: '" << text[i] << "' != '" << pattern[j] 
                     << "', move to next text char" << endl;
                i++;
            }
        }
    }
    delete[] lps;
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
    const char* text = "ababababc";
    const char* pattern = "abab";
    int maxMatches = getLength(text);
    int* results = new int[maxMatches];
    int count = 0;
    KMPSearch(text, pattern, results, count);
    cout << "\n=== Final Result ===" << endl;
    cout << "Pattern \"" << pattern << "\" found at positions: ";
    displayResults(results, count);
    cout << "Total matches: " << count << endl;
    const char* text2 = "AABAACAADAABAABA";
    const char* pattern2 = "AABA";
    int count2 = 0;
    KMPSearch(text2, pattern2, results, count2);
    cout << "\n=== Final Result ===" << endl;
    cout << "Pattern \"" << pattern2 << "\" found at positions: ";
    displayResults(results, count2);
    cout << "Total matches: " << count2 << endl;
    delete[] results;
    return 0;
}
