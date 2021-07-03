// NOTE: Template classes MUST be implemented in the header file, otherwise the compiler throws errors.

#include <iostream>
#include "Node.h"

using namespace std;

template<class T>
class LinkedList {
private:
    Node<T> * head;
public:
    ~LinkedList() {
        clear();
        cout << "Freeing allocated memory for the structure!" << endl;
    }

    Node<T> * at(int n) {
        Node<T> * current = head;
        for (int i = 0; i < n; i++) {
            current = current->next;
        }
        
        return current;
    }

    void insert(T data) {
        Node<T> * node = new Node<T>();
        node->data = data;
        node->next = NULL;

        if (head == NULL) {
            // If head is null, insert the new node at head
            head = node;
        } else {
            // Insert the new node after the last node
            Node<T> * current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void print(int col) {
        bool isFirstRow = true;
        if (col == 2 || col == 3) {
            cout << "-----------" << endl;
        }
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
        } else {
            Node<T> * current = head;
            while (current != NULL) {
                if (isFirstRow) {
                    cout << " " << current->data << " ";
                    current = current->next;
                    isFirstRow = false;
                } else {
                    cout << "| " << current->data << " ";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }

    void clear() {
        Node<T> * tmp = NULL;
        while(head != NULL) {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }

};