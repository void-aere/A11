#include "unorderedLinkedList.hpp"

template <class Type>
bool UnorderedLinkedList<Type>::search(const Type& query) const {
    Node<Type>* current = head;
    while (current != nullptr) {
        if (*(current->data) == query) return true;
        current = current->next;
    }
    return false;
}

template <class Type>
void UnorderedLinkedList<Type>::insertFirst(Type* data) {
    Node<Type>* newNode = new Node<Type>;
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    ++count;

    if (tail == nullptr) tail = newNode;
}

template <class Type>
void UnorderedLinkedList<Type>::insertLast(Type* data) {
    Node<Type>* newNode = new Node<Type>;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
       tail->next = newNode;
       tail = newNode;
    }

    ++count;
}

template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type& query) {
    Node<Type>* current;
    Node<Type>* temp;
    bool found;

    if (head != nullptr) {
        if (*(head->data) == query) {
            current = head;
            head = head->next;
            --count;
            if (head == nullptr) tail = nullptr;
            delete current;
        } else {
            found = false;
            temp = head;
            current = head->next;

            while (current != nullptr && !found) {
                if (*(current->data) != query) {
                    temp = current;
                    current = current->next;
                } else found = true;
            }

            if (found) {
                temp->next = current->next;
                --count;

                if (tail == current) tail = temp;

                delete current;
            }
        }
    }
}
