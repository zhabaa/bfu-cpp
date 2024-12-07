#include <iostream>
#include "func.hpp"

using namespace linkedList;

int main() {
    int n;

    std::cout << "Enter lenght: ";
    std::cin >> n;

    linkedList::Node* head;
    linkedList::make(head);

    bool hadGoodDigits = false;

    for (int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;

        if (isGoodNumber(input)) {
            hadGoodDigits = true;
        }

        linkedList::pushback(head, input);
    }

    std::cout << "initial sequence: ";
    linkedList::print(head);

    if (hadGoodDigits) {
        linkedList::sortLinkedList(head);

    } else {
        for (int i = 0; i < n; i++) {
            if (!(CountDigits(linkedList::get(head, i) -> data) % 2)) {
                linkedList::pop(head, i);
                n--;
            }
        }

        for (int i = 0; i < n; i += 2) {
            linkedList::indexCopy(head, i);
            n++;
        }
    }

    std::cout << "result sequence: ";
    linkedList::print(head);

    linkedList::clear(head);
    return 0;
}
