#include "linkedList.hpp"

#include <iostream>
#include <cassert>

template <class Type>
LinkedListIterator<Type>::LinkedListIterator() {
    current = nullptr;
}

template <class Type>
LinkedListIterator<Type>::LinkedListIterator(Node<Type>* node) {
    current = node;
}

template <class Type>
Type LinkedListIterator<Type>::operator*() {
    return *(current->data);
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++() {
    current = current->next;
    return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator<Type>& right) const {
    return (current == right.current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator<Type>& right) const {
    return (current != right.current);
}

template <class Type>
bool LinkedList<Type>::isEmptyList() const {
    return head == nullptr;
}

template <class Type>
LinkedList<Type>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class Type>
void LinkedList<Type>::destroyList() {
    Node<Type>* temp;

    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }

    tail = nullptr;
    count = 0;
}

template <class Type>
void LinkedList<Type>::initializeList() {
    destroyList();
}

template <class Type>
void LinkedList<Type>::print() const {
    Node<Type>* current = head;

    while (current != nullptr) {
        std::cout << *(current->data) << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template <class Type>
int LinkedList<Type>::length() const {
    return count;
}

template <class Type>
Type LinkedList<Type>::front() const {
    assert(head != nullptr);
    return *(head->data);
}

template <class Type>
Type LinkedList<Type>::back() const {
    assert(tail != nullptr);
    return *(tail->data);
}

template <class Type>
LinkedListIterator<Type> LinkedList<Type>::begin() {
    return LinkedListIterator<Type>(head);
}

template <class Type>
LinkedListIterator<Type> LinkedList<Type>::end() {
    return LinkedListIterator<Type>(tail);
}

template <class Type>
void LinkedList<Type>::copyList(const LinkedList<Type>& other) {
    Node<Type>* current;

    destroyList();
    
    if (other.head != nullptr) {
        current = other.head;
        while (current != nullptr) {
            insertLast(new Type(*(current->data)));
            current = current->next;
        }
    }
}

template <class Type>
LinkedList<Type>::~LinkedList() {
    destroyList();
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& other) {
    head = nullptr;
    copyList(other);
}

template <class Type>
LinkedList<Type>&  LinkedList<Type>::operator=(const LinkedList<Type>& other) {
    if (this != &other) {
        copyList(other);
    }

    return *this;
}
