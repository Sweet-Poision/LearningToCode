#include <iostream>
using namespace std;

template <typename T>
class List {
    private: 
    T *arr;
    int count;
    int capacity;
    public:
    List() {
        arr = NULL;
        count = 0;
        capacity = 0;
    }
    List(T size, T initialiser) {
        arr = new T[size*2];
        for(int i = 0; i < size; i++) arr[i] = initialiser;
        count = size;
        capacity = count*2;
    }
    void push_back(T data) {
        if(arr == NULL) {
            T *temp = new T[2];
            *(temp) = data;
            capacity = 2;
            count = 1;
            return;
        }
        count++;
        if(count >= capacity) {
            T *temp = new T[capacity*2];
            for(int i = 0; i < count-1; i++) {
                *(temp + i) = *(arr + i);
            }
            *(temp + count - 1) = data;
            arr = temp;
            capacity *= 2;
            return;
        }
        *(arr + count - 1) = data;
    }
    int size() {
        return count;
    }
    int cap() {
        return capacity;
    }

};

int main() {
    List<int> l;
    cout << "size: " << l.size() << " " << l.cap() << endl;
    l.push_back(1);
    cout << "size: " << l.size() << " " << l.cap() << endl;
    l.push_back(4);
    cout << "size: " << l.size() << " " << l.cap() << endl;
    l.push_back(1);
    cout << "size: " << l.size() << " " << l.cap() << endl;
    l.push_back(4);
    cout << "size: " << l.size() << " " << l.cap() << endl;

    // l.push_back(2);
    // cout << l.size() << endl;
    // l.push_back(10);
    // cout << l.size() << endl;

}