#include <iostream>
using namespace std;

class CircularLinkedList {
    private:
        struct Node {

            int data;
            Node * next;
        };
        Node * head;    // contains the address of head node
    public:
        // constructor for initialising the head node with NULL value
        CircularLinkedList() {

            head = NULL;
        }

        // function to push data at end of the list
        void push(int data) {
            
            Node * temp;
            temp = new Node();
            temp->data = data;
            if(head == NULL) {

                head = temp;
                head->next = head;
                return;
            }
            Node * pointer = head;
            while(pointer->next != head) {

                pointer = pointer->next;
            }
            pointer->next = temp;
            temp->next = head;
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
            if(count == this->size()) {
                pointer->next->next = head;
            }
        }

        // function to remove data from list at any position (first position is 1)
        void remove(int index) {

            int count = 1;
            Node * temp = head;
            if(temp == NULL) return;
            if(index == 1) {
                Node * temp = head;
                while(temp->next != head) {
                    
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                return;
            }
            count++;
            temp = temp->next;
            while(temp->next != head) {

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
            if(temp == NULL) return;
            cout << temp->data << " ";
            temp = temp->next;
            while(temp != head) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        // funciton to count elements in the linked list
        int size() {

            int count = 0;
            Node * temp = head;
            if(temp==NULL) return 0;
            temp = temp->next;
            count++;
            while(temp != head) {

                count++;
                temp = temp->next;
            }
            return count;
        }
};

int main() {
    CircularLinkedList cll;
    for(int i = 0; i < 5; i++) cll.push(i);
    // list after this -> 0 1 2 3 4

    cll.push(10,3);
    // list after this -> 0 1 10 2 3 4
    
    cll.remove(1);
    // list after this -> 1 10 2 3 4
    
    // printing the linked list
    cll.print();

}