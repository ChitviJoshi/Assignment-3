#include <iostream>
#include <stack>
using namespace std;

string reverseUsingStack(const string& input) {
    stack<char> s;
    for (char ch : input) {
        s.push(ch);}
    string rev;
    while (!s.empty()) {
        rev += s.top();
        s.pop();}
    return rev;}

int main() {
    cout << "Enter a string: ";
    string str1;
    getline(cin, str1);
    string rev_str = reverseUsingStack(str1);
    cout << "Reversed string: " << rev_str << endl;
    return 0;
}
