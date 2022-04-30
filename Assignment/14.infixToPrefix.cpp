#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool isOperand(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int precedence (char c) {
    map<char, int> mp {{'^', 3}, {'/', 2}, {'*', 2}, {'%', 2}, {'+', 1}, {'-', 1}};
    return mp[c];
}

string intfixToPrefix(string str) {
    stack<char> s;
    string prefix = "";
    reverse(str.begin(), str.end());
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == ' ') continue;
        else if(isOperand(str[i])) {
            prefix.push_back(str[i]);
        } 
        else if(s.empty()) s.push(str[i]);
        else if(str[i] == ')') s.push(str[i]);
        else if(str[i] == '(') {
            while(s.top() != ')') {
                prefix.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(precedence(str[i]) >= precedence(s.top())) s.push(str[i]);
        else {
            while(!s.empty() && precedence(s.top()) > precedence(str[i])) {
                prefix.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty()) {
        prefix.push_back(s.top());
        s.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix = "K + L - M*N + (O^P) * W/U/V * T + Q";
    cout << intfixToPrefix(infix) << endl;
    return 0;
}
