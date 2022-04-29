#include <iostream>
#include <stack>
using namespace std;

bool isNumber(char c) {
    if( c >= '0' and c <= '9') return true;
    return false;
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

string operate(string a, string b, char op) {
    int numa = stoi(a);
    int numb = stoi(b);
    int res;
    if(op == '+') res = numb + numa;
    else if(op == '-') res = numb - numa;
    else if(op == '*') res = numb * numa;
    else if(op == '/') res = numb / numa;
    return to_string(res);
}

void checkExpress(const string &str) {
    stack<string> s;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == ' ') {
            continue;
        }
        if(isNumber(str[i])) {
            string number;
            while(isnumber(str[i])) {
                number.push_back(str[i]);
                i++;
            }
            s.push(number);
        }
        else if(isOperator(str[i])) {
            string a = s.top();
            s.pop();
            string b = s.top();
            s.pop();
            s.push(operate(a,b,str[i]));
        }
        else {
            cout << "Expression is wrong" << endl;
            return;
        }
    }
    if(s.size() == 1) {
        cout << s.top() << endl;
        return;
    }
    cout << "ERROR" << endl;
}

int main() {
    // works only with ideal expressions
    string expression = "4312 3 1 * + 9 -";
    checkExpress(expression);
}