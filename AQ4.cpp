#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char op) {
    if (op == '^') return 3;      
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;}
int main() {
    string infix, postfix = "";
    stack<char> s;
    cout << "Enter infix expression (e.g., A+B*C^D): ";
    cin >> infix;
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {

            postfix += ch;} 
        else if (ch == '(') {
            s.push(ch);} 
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();}
            s.pop(); } 
        else {
            while (!s.empty() && getPrecedence(s.top()) > getPrecedence(ch)) {
                postfix += s.top();
                s.pop();}
            s.push(ch);}
        }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();}
    cout << "Postfix expression: " << postfix << endl;
    return 0;}
