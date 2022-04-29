#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Initialising a string
    string str = "Hello World";

    // Declaring a stack
    stack<char> s;

    // putting characters of string in stack
    for(auto &it: str) s.push(it);

    // declaring a null string which will contain the reversed string
    string reversed_str = "";
    
    // reversing the string using stack
    while(!s.empty()) {
        reversed_str.push_back(s.top());
        s.pop();
    }

    // Printing Reversed Array
    cout << reversed_str << endl;
}