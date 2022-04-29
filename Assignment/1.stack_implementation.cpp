#include <iostream>
using namespace std;

class Stack {
    private:
        int *arr;
        const int MAX = 100;
        int count;
    public:
        Stack() {
            arr = new int[MAX];
            count = 0;
        }
    bool isEmpty() {
        if (count == 0) return true;
        return false;
    }
    bool isFull() {
        if(count == MAX) return true;
        return false;
    }
    void push(int data) {
        if(count == MAX) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[count++] = data; 
    }
    int pop() {
        if(count == 0) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[--count];
    }
};

int main() {
    Stack s;
    for(int i = 0; i < 5; i++) s.push(i);
    while(s.isEmpty() == false) {
        cout << s.pop() << " ";
    }
}