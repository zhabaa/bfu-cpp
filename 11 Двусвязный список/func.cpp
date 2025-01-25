#include <iostream>
#include "func.hpp"

namespace ddl {
    void make(Node *&sent) {
        sent = new Node;
        sent -> next = sent;
        sent -> prev = sent;
    };

    void push_back(Node* sent, int value) {
        Node* curr = new Node;

        curr -> data = value;
        curr -> next = sent;
        curr -> prev = sent -> prev;

        sent -> prev -> next = curr;
        sent -> prev = curr;
    };

    void push_front(Node* sent, int value) {
        Node* curr = new Node;

        curr -> data = value;
        curr -> next = sent -> next;
        curr -> prev = sent;

        sent -> next -> prev = curr;
        sent -> next = curr;
    };

    void print(Node* sent) {
        Node* curr = sent -> next;

        while (curr != sent) {
            std::cout << curr -> data << " ";
            curr = curr -> next;
        }

        std::cout << std::endl;
    };

    void clear(Node* sent) {
        Node* curr = sent -> next;
        Node* next;

        while (curr != sent) {
            next = curr -> next;
            delete curr;
            curr = next;
        }

        delete sent;
    };

    void remove(Node* sent) {
        /* remove by even value */

        Node* curr = sent -> next;
        Node* prev;

        while (curr != sent) {
            prev = curr -> prev;

            if (isAllOdd(curr -> data)) {
                prev -> next = curr -> next;
                curr -> next -> prev = prev;
                delete curr;
            }

            curr = curr -> next;
        }
    }

    void duplicate(Node* sent) {
        Node* curr = sent -> next;
        Node* next;

        while (curr != sent) {
            next = curr -> next;

            if (isEven(curr -> data)) {
                Node* new_node = new Node;
                new_node -> data = curr -> data;
                new_node -> next = curr -> next;
                new_node -> prev = curr;

                curr -> next -> prev = new_node;
                curr -> next = new_node;
            }

            curr = next;
        }
    }

    void bSort(Node* sent) {
        Node* curr = sent -> next;
        Node* next;
        int temp;

        while (curr != sent) {
            next = curr -> next;

            while (next != sent) {
                if (curr -> data < next -> data) {
                    temp = curr -> data;
                    curr -> data = next -> data;
                    next -> data = temp;
                }

                next = next -> next;
            }

            curr = curr -> next;
        }
    }

}

bool isPrime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        } 
    }

    return true;
}

bool isEven(int num) {
    return num % 2 == 0;
}

bool isAllOdd(int num) {
    while (num > 0) {
        if (isEven(num % 10)) {
            return false;
        }
        num /= 10;
    }
    return true;
}
