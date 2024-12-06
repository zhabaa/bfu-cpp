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
        // Отсортировать если есть трехзначные числа, состоящие только из четных цифр
        linkedList::sort(head);

        std::cout << "1";


    } else {
        // Удалить все числа с четным кол-вом цифр
        // Продублировать оставшиеся

        for (int i = 0; i < n; ++i) {
            if (!(CountDigits(linkedList::get(head, i) -> data) % 2)) {
                linkedList::pop(head, i);
            } else {
                linkedList::indexCopy(head, i);
            }
        }
    }

    std::cout << "result sequence: ";
    linkedList::print(head);

    linkedList::clear(head);

    return 0;
}
