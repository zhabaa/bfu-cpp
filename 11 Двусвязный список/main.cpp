#include <iostream>
#include "func.hpp"

using namespace ddl;

bool hasPrime(Node *sent) {
    bool flag = false;

    Node* curr = sent -> next;

    while (curr!= sent) {
        if (isPrime(curr -> data)) {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

int main() {
    Node* sent = new Node;
    sent -> next = sent;
    sent -> prev = sent;

    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int data;
        std::cout << ">> ";
        std::cin >> data;
        push_back(sent, data);
    }

    std::cout << "List: ";
    print(sent);
    
    if (hasPrime(sent)) {
        remove(sent);
        duplicate(sent);

    } else {
        bSort(sent);
    };

    std::cout << "Result list: ";
    print(sent);
    clear(sent);

    return 0;
}
