#include <iostream>
using namespace std;

class Stack {
    private:
        int *arr;
        const int MAX = 100;
        int c1, c2;
    public:
        Stack() {
            arr = new int[MAX];
            c1 = -1;
            c2 = MAX;
        }
    bool isEmptyFirst() {
        if(c1 == -1) return true;
        return false;
    }
    bool isEmptySecond() {
        if(c2 == MAX) return true;
        return false;
    }
    bool isEmpty() {
        if(c1 == -1 and c2 == MAX) return true;
        return false;
    }
    bool isFull() {
        if(c2-c1 == 1) return true;
        return false;
    }
    void pushFirst(int data) {
        if(isFull() == true ) {
            cout << "No Space in Stack" << endl;
            return;
        }
        arr[++c1] = data;
    }
    void pushSecond(int data) {
        if(isFull() == true) {
            cout << "No Spacce in Stack" << endl;
            return;
        }
        arr[--c2] = data;
    }
    int popFirst() {
        if(isEmptyFirst() == true) {
            cout << "Stack already Empty" << endl;
            return -1;
        }
        return arr[c1--];
    }
    int popSecond() {
        if(isEmptySecond() == true) {
            cout << "Stack already empty" << endl;
            return -1;
        }
        return arr[c2++];
    }
};

int main() {
    Stack s;
    for(int i = 0, j = 10; i < 5; ++i, --j) {
        s.pushFirst(i);
        s.pushSecond(j);
    }
    // printing first stack
    while(s.isEmptyFirst() == false) {
        cout << s.popFirst() << " ";
    }
    cout << endl;
    // printing the second stack
    while(s.isEmptySecond() == false) {
        cout << s.popSecond() << " ";
    }
    cout << endl;
}