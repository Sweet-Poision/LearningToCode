#include <iostream>
using namespace std;

struct LinkedList {
	struct Node {
		int data;
		struct Node* next = NULL;
		Node(int data) {
			this->data = data;
		}
	};
	Node* head = NULL;
    Node* current = NULL;
    int count = 0;

	Node* reverseList(Node* node) {
		if (node == NULL)
			return NULL;
		if (node->next == NULL) {
			head = node;
			return node;
		}
		Node* node1 = reverseList(node->next);
		node1->next = node;
		node->next = NULL;
		current = node;
		return node;
	}

	void reverse() {
		reverseList(head);
	}

    int size() {
        return count; 
    }
    
	void print() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data) {
		Node* temp = new Node(data);
		if(count == 0) head = temp;
		else current->next = temp;
		current = temp;
		count++;
	}
};

int main() {
	LinkedList l;
    int n, x;
    cout << "Give total elements: ";
    cin >> n;
    if(n>0) {
        cout << "Give elements: \n";
        for(int i=0; i<n; i++) {
            cin >> x;
            l.push(x);
        } 
        cout << "Given linked list\n";
	    l.print();
	    l.reverse();
	    cout << "\nReversed Linked list \n";
	    l.print();
    }
	return 0;
}