#include <iostream>
using namespace std;

// creating a class LinkedList
class LinkedList {
    private:
        struct Node {

            int data;
            Node * next;
        };
        Node * head;    // contains the address of head node
    public:
        // constructor for initialising the head node with NULL value
        LinkedList() {

            head = NULL;
        }

        // function to push data at end of the list
        void push(int data) {
            
            Node * temp;
            temp = new Node();
            temp->data = data;
            if(head == NULL) {

                head = temp;
                head->next = NULL;
                return;
            }
            Node * pointer = head;
            while(pointer->next != NULL) {

                pointer = pointer->next;
            }
            pointer->next = temp;
        }

        // functino to push data at any position ( first position is cout as 1)
        void push(int data, int i) {

            Node * temp = new Node();
            temp -> data = data;
            temp->next = NULL;
            if( i == 1) {

                temp->next = head;
                head = temp;
                return;
            }
            int count = 1;
            Node * pointer = head;
            while(pointer->next != NULL) {

                if(abs(count - i) == 1) {

                    break;
                }
                else {

                    count++;
                    pointer = pointer->next;
                }
            }
            temp -> next = pointer -> next;
            pointer->next = temp;
        }

        // function to remove data from list at any position (first position is 1)
        void remove(int index) {

            int count = 1;
            Node * temp = head;
            if(index == 1) {
                head = head->next;
                return;
            }
            while(temp->next != NULL) {

                if(index - count == 1) {

                    break;
                }
                temp = temp->next;
            }
            if(temp->next == NULL) {

                return;
            }
            temp -> next = temp->next->next;
        }

        // function to print the linked list
        void print() {
            Node * temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList ll;
    for(int i = 0; i < 5; i++) ll.push(i);
    // list after this -> 0 1 2 3 4

    ll.push(10,3);
    // list after this -> 0 1 10 2 3 4
    
    ll.remove(1);
    // list after this -> 1 10 2 3 4
    
    // printing the linked list
    ll.print();
}