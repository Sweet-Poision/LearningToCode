#include <iostream>
using namespace std;

class Queue {
    private:
        int *arr;
        int count, MAX, current;
    public:
        Queue() {
            count = 0;
            current = 0;
            MAX = 100;
            arr = new int[MAX];
        }
        bool isFull() {
            if(count == MAX) return true;
            return false;
        }
        bool isEmpty() {
            if(count == 0) return true;
            return false;
        }
        void inqueue(int data) {
            if(this->isFull()) {
                cout << "Stack is Full" << endl;
                return;
            }
            arr[count+current] = data;
            count++;
        }
        int dequeue() {
            if(this->isEmpty()) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            current++;
            count--;
            return arr[current - 1];
        }
};

int main() {
    Queue q;
    for(int i = 0; i < 5; i++) q.inqueue(i);
    while(!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
}