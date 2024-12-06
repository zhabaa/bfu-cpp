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
    while (x % 10 > 0) {
        x /= 10;
    }
    return x;
}

namespace linkedList {

    void make(Node *&head) {
        head = new Node{0, nullptr};
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

    /* didnt
    void remove(Node *head, int value) {
         delete by value 

        Node *curr = head;

        while (curr != nullptr && curr -> next -> data != value) {
            curr = curr -> next;
        }

        if (curr == nullptr) {
            return;
        }

        Node *tmp = curr -> next;
        curr -> next = curr -> next -> next;

        delete tmp;
    }
*/

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

    /* didnt 
    void copy(Node *head, int value) {
         copy element by value 

        Node *curr = head;

        while (curr -> next != nullptr && curr -> data != value) {
            curr = curr -> next;
        }

        if (curr == nullptr) {
            return;
        }

        Node *newNode = new Node;
        newNode -> data = value;
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
*/

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

    Node *Check(Node *newNode, Node *sorted) {
        if (sorted == nullptr || getFirstDigit(sorted -> data) >= getFirstDigit(newNode -> data)) {
            newNode -> next = sorted;
            sorted = newNode;

        } else {
            Node *curr = sorted;

            while (curr->next != nullptr && getFirstDigit(curr -> next -> data) < getFirstDigit(newNode -> data)) {
                curr = curr -> next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }

        return sorted;
    }

    Node *sort(Node *head) {
        Node *sorted = nullptr;
        Node *curr = head;

        while (curr != nullptr) {
            Node *next = curr -> next;
            sorted = Check(curr, sorted);
            curr = next;
        }

        return sorted;

    }
}
