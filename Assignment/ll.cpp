#include <iostream>
using namespace std;

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
        void removeAt(int index) {
            // if(index > this->size()) {
                // IllegalArgumentException
            // }
            int count = 1;
            Node * temp = head;
            if(index == 1) {
                head = head->next;
                return;
            }
            try {
                if(index > this->size()) {
                    throw index;
                }
                while(index-count < 1) {
                temp = temp->next;
                }
            }
            catch (int ex) {
                cout << "IllegalArguementException";
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
        // funciton to count elements in the linked list
        int size() {

            int count = 0;
            Node * temp = head;
            while(temp != NULL) {

                count++;
                temp = temp->next;
            }
            return count;
        }
    void get(int n) {
        Node * temp = head;
        try {
            if(n > this->size()) 
                throw n;
            
            for(int i = 1; i < n; i++) {
                temp = temp->next;
            }
            cout << temp->data;
        }
        catch(int ex) {
            cout << "IllegalArguementException";
        }
        
    }
};

int main() {
    LinkedList ll;
    for(int i = 0; i < 5; i++) ll.push(5);
    ll.get(11);
}