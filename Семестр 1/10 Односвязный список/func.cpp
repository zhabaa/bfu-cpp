#include <iostream>
#include "func.hpp"

bool isEven(int x) {
    return !(x % 2);
}

bool isAllDigitsEven(int x) {
    while (x > 0) {
        if (!isEven(x % 10)) {
            return false;
        }
        x /= 10;
    }
    return true;
}

bool isGoodNumber(int x) {
    if (x < 100 || x > 999) {
        return false;
    } else {
        return isAllDigitsEven(x);
    }
}

int CountDigits(int x) {
    int count = 0;

    while (x > 0) {
        x /= 10;
        count++;
    }
    return count;
}

int getFirstDigit(int x) {
    while (x / 10 > 0) {
        x /= 10;
    }
    return x;
}

namespace linkedList {

    void make(Node *&head) {
        head = new Node {0, nullptr};
    }

    void pushback(Node *head, int value) {
        Node *curr = head;

        while (curr -> next != nullptr) {
            curr = curr -> next;
        }

        Node *newNode = new Node;

        newNode -> data = value;
        newNode -> next = nullptr;

        curr -> next = newNode;
    }

    void print(Node *head) {
        Node *curr = head;

        while (curr -> next != nullptr) {
            curr = curr -> next;
            std::cout << curr -> data << " ";
        }
        std::cout << std::endl;
    }

    int size(Node *head) {
        Node *curr = head;

        int count = 0;

        while (curr -> next != nullptr) {
            curr = curr -> next;
            count++;
        }

        return count;
    }

    void pop(Node *head, int index) {
        /* delete by index */

        Node *curr = head;
        int ind = 0;

        while (curr -> next != nullptr && ind != index) {
            curr = curr -> next;
            ind++;
        }

        if (curr -> next == nullptr) {
            return;
        }

        Node *temp = curr -> next;
        curr -> next = curr -> next -> next;

        delete temp;
    }

    void clear(Node *head) {
        Node *curr = head;

        while (curr != nullptr) {
            Node *tmp = curr;
            curr = curr -> next;
            delete tmp;
        }
    }

    void indexCopy(Node *head, int index) {
        /* duplicate value by index */

        Node *curr = head;
        int curr_index = 0;

        while (curr -> next != nullptr && curr_index != index) {
            curr = curr->next;
            curr_index++;
        }

        if (curr -> next == nullptr) {
            return;
        }

        if (index >= 0) {
            curr = curr -> next;
            Node *newNode = new Node;
            newNode -> data = curr -> data;
            newNode -> next = curr -> next;
            curr -> next = newNode;
        }
    }

    Node *get(Node *head, int index) {
        /* get element index */

        Node *curr = head;
        int curr_index = 0;

        while (curr -> next != nullptr && curr_index != index) {
            curr = curr -> next;
            curr_index++;
        }

        if (curr -> next == nullptr) {
            return nullptr;
        }

        if (index >= 0) {
            return curr -> next;
        }
    }

    void sortLinkedList(Node *head) {
        Node *curr = head;
        Node *temp = nullptr;

        int t;

        if (head == nullptr) {
            return;
        }

        while (curr != nullptr) {
            temp = curr -> next;

            while (temp != nullptr) {
                if (getFirstDigit(curr -> data) > getFirstDigit(temp -> data)) {
                    t = curr -> data;
                    curr -> data = temp -> data;
                    temp -> data = t;
                }
                temp = temp -> next;
            }
            curr = curr -> next;
        }
    }
}