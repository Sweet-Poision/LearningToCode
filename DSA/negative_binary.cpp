#include <iostream>
using namespace std;

int bin(int n) {
    
}

int main() {
    int n;
    cin >> n;
    if(n >= 0) {
        cout << bin(n) << endl;
    }
    else
        cout << negbin(n) << endl;
}