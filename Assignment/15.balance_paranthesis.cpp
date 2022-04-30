#include <iostream>
#include <stack>
using namespace std;

bool isOpening(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isPair(char b, char a) {
    return ((a=='(' && b == ')') || (a == '{' && b == '}') || (a == '[' || b == ']'));
}

bool isBracket(char c) {
    char arr[6] = {'(', ')', '{', '}', '[', ']'};
    for(int i = 0; i < 6; i++)
        if(arr[i] == c) return true;
    return false;
}

bool isOk(string exp) {
    stack<char> s;
    for(int i = 0; i < exp.size(); i++)
        if(!isBracket(exp[i])) continue;
        else if(isOpening(exp[i])) s.push(exp[i]);
        else
            if(s.empty()) return false;
            else if(isPair(exp[i], s.top())) s.pop();
            else return false;
    return s.empty();
}

int main() {
    // string s = "a ( b { d e [ f ] g { h } I } j k ) l m";
    string s =  "( a b { c } d ( [ e [ f ] g ] ) ( j ) )";
    if(isOk(s))
        cout << "Paranthesis is correct" << endl;
    else 
        cout << "Paranthesis is mismatched" << endl;
    return 0;
}