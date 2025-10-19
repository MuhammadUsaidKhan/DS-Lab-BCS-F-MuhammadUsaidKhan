#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class CharStack {
private:
    char arr[100];
    int top;
public:
    CharStack() { top = -1; }
    void push(char c) {
        if (top < 99) arr[++top] = c;
    }
    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }
    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
class IntStack {
private:
    int arr[100];
    int top;
public:
    IntStack() { top = -1; }
    void push(int n) {
        if (top < 99) arr[++top] = n;
    }
    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}
bool isRightAssociative(char op) {
    return (op == '^');
}
string reverseStr(string s) {
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--) rev += s[i];
    return rev;
}
void swapParentheses(string &exp) {
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}
string infixToPrefix(string infix) {
    CharStack s;
    string prefix = "";
    infix = reverseStr(infix);
    swapParentheses(infix);
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            prefix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                prefix += s.pop();
            s.pop(); 
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && 
                  ((precedence(s.peek()) > precedence(c)) ||
                  (precedence(s.peek()) == precedence(c) && !isRightAssociative(c))) &&
                  (s.peek() != '(')) {
                prefix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        prefix += s.pop();
    }
    prefix = reverseStr(prefix);
    return prefix;
}
int evaluatePrefix(string prefix) {
    IntStack s;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            int val1 = s.pop();
            int val2 = s.pop();
            int res = 0;
            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': res = pow(val1, val2); break;
            }
            s.push(res);
        }
    }
    return s.pop();
}
int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands only): ";
    getline(cin, infix);
    string prefix = infixToPrefix(infix);
    cout << "\nPrefix Expression: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    cout << "Evaluation Result: " << result << endl;
    return 0;
}
