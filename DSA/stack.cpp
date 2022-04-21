#include <iostream>
using namespace std;
//stack using linked list

struct Node {
    int data;
    Node * next = NULL;
};

void push(Node ** head, int d) {
    Node * temp = new Node();
    temp->data = d;
    if(*head == NULL) {
        *head = temp;
    }
    else {
        temp->next = *head;
        *head = temp;
    }
}

void pop(Node ** head) {
    if(*head == NULL) return;
    Node * temp = (*head)->next;
    delete *head;
    *head = temp;
}

int top(Node ** head) {
    return ((*head)==NULL) ? -1:(*head)->data;
}

int main() {    
    Node * head = NULL;
    push(&head, 5);
    push(&head, 5);
    pop(&head);
    cout << top(&head) << endl;
}