#include <iostream>
#include <cmath> 
#include <string>
using namespace std;
class CharStack {
private:
    char arr[100];
    int top;
public:
    CharStack() { top = -1; }
    void push(char c) {
        if (top < 99) arr[++top] = c;
        else cout << "Stack Overflow!" << endl;
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
        else cout << "Stack Overflow!" << endl;
    }
    int pop() {
        if (top == -1) return -1;
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string infixToPostfix(string infix) {
    CharStack s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}
int evaluatePostfix(string postfix) {
    IntStack s;
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (c == ' ') continue;
        if (c >= '0' && c <= '9') {
            s.push(c - '0'); 
        }
        else if (isOperator(c)) {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;
            switch (c) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
            }
            s.push(result);
        }
    }
    return s.pop();
}
int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands only): ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "\nPostfix Expression: " << postfix << endl;
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;
    return 0;
}
