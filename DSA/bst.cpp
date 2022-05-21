#include <iostream>
using namespace std;

template <typename T>

class bst {
    private:
        struct bstNode {
            T data;
            bstNode * left;
            bstNode * right;
        };
    protected:
        bstNode * root;
    public:
        bst() {
            root = NULL;
        }
        void insert(T value) {
            bstNode * temp = new bstNode;
            temp->data = value;
            temp->left = NULL;
            temp->right = NULL;
            if(root == NULL) {
                root = temp;
                return;
            }
            bstNode * it = root;
            while(true) {
                if(it->data == value) return;
                else if(it->data > value) {
                    if(it->left == NULL) {
                        it->left = temp;
                        return;
                    }
                    it = it->left;
                }
                else if(it->data < value) {
                    if(it->right == NULL) {
                        it->right = temp;
                        return;
                    }
                    it = it->right;
                }
            }
        }
        void printFunctionInternal(bstNode * ptr) {
            if(ptr == NULL) return;
            printFunctionInternal(ptr->left);
            cout << ptr->data << " ";
            printFunctionInternal(ptr->right);
        } 
        void print() {
            printFunctionInternal(root);
        }
        bool search(T value) {
            bstNode * it = root;
            while(true) {
                if(it == NULL) return false;
                else if(it->data == value) return true;
                else if(it->data < value) it = it->right;
                else if(it->data > value) it = it->left;
            }
        }
    // implement function to delete a node in binary search tree
    // function name should be "remove" and it should take only one parameter that 
    // is the element which needs to be removed from the Binary Search Tree
};

int main() {
    bst<int> a;
    a.insert(4);
    a.insert(4);
    a.insert(99);
    a.insert(3);
    a.insert(10);
    a.insert(1);
    a.print();
    cout << endl;
    // a.remove(4);
    a.print();
}