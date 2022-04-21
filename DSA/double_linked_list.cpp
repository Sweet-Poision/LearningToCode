#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next = NULL;
    Node * prev = NULL;
};

void insert(Node ** head, int d) {
    Node * temp = new Node();
    temp->data = d;
    Node * ptr2 = *head;
    if(*head == NULL) {
        *head = temp;
    }
    else {
        while(ptr2->next != NULL) {
            ptr2 = ptr2->next;
        }
        ptr2->next = temp;
        temp->prev = ptr2;
    }
}

void printList(Node * head) {
    Node * temp = head;
    Node * ptr = NULL;
    while(temp != NULL) {
        cout << temp->data << " ";
        ptr = temp;
        temp = temp->next;
    }
    temp = ptr;
    while (temp != NULL) {
        cout << temp->data << " ";
        ptr = temp;
        temp = temp->prev;
    }
} 

int main() {
    Node * head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    printList(head);
}