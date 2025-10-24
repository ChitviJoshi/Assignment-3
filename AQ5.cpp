#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

int applyOperator(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

int main() {
    string expr;
    cout << "Enter postfix expression (space-separated): ";
    getline(cin, expr);

    stack<int> s;
    istringstream iss(expr);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(applyOperator(a, b, token[0]));
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}
