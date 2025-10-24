#include <iostream>
#include <stack>
using namespace std;

bool bal(string s){
    stack<char> s_str1;
    for(char ch: s){
        if (ch == '(' || ch == '{' || ch == '[') {
            s_str1.push(ch);}
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s_str1.empty()) return false;
            char top = s_str1.top();
            s_str1.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;}}}
    return s_str1.empty();}

int main(){
    string str1="{[()]}";
    if(bal(str1)){
        cout<<"Balanced parenthesis";}
    else{
        cout<<"Imbalanced";
    }
    return 0;
}
