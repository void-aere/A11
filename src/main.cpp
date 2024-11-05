#include <iostream>
#include "unorderedLinkedList.hpp"

int main() {
    UnorderedLinkedList<int> list1, list2;
    int num;

    std::cout << "Enter integers ending with -999" << std::endl;

    int* intPtr;
    do {
        std::cin >> num;
        intPtr= new int(num);
        if (num == -999) break;
        list1.insertLast(intPtr);
    } while (num != -999);
    delete intPtr;

    std::cout << "\nlist1: ";
    list1.print();

    std::cout << "Length of list1: " << list1.length() << std::endl;

    list2 = list1;

    std::cout << "\nlist2: ";
    list2.print();

    std::cout << "Length of list2: " << list2.length() << std::endl;

    std::cout << "\nEnter the number to be deleted: ";
    std::cin >> num;
    list2.deleteNode(num);

    std::cout << "list2 after deleting: ";
    list2.print();

    std::cout << "Length of list2: " << list2.length() << std::endl;

    std::cout << "\nOutput list1 with an iterator:" << std::endl;
    LinkedListIterator<int> it;
    for (it = list1.begin(); it != ++(list1.end()); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";

    return 0;
}
