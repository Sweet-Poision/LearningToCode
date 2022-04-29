#include <iostream>
#include <stack>
#include <map>
using namespace std;

bool isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool precedence(char a, char b) {
    map<char, int> m { {'^', 3}, {'/', 2}, {'*', 2}, {'%', 2}, {'+', 1}, {'-', 1} };
    return m[a] > m[b];
}

string infixToPostfix(string exp) {
    string postfix = "";
    stack<char> s;
    for(int i = 0; i < exp.size(); i++) {
        if(exp[i] == ' ') continue;
        if(isOperand(exp[i])) postfix += exp[i];
        else if(exp[i] == '(') s.push('(');
        else if(exp[i] == ')') {
            while(s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(s.empty()) s.push(exp[i]);
        else if(precedence(exp[i], s.top())) s.push(exp[i]);
        else {
            while(!s.empty() && !precedence(exp[i], s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string expression = "K + L - M*N + (O^P) * W/U/V * T + Q";
    cout << infixToPostfix(expression) << endl;
}