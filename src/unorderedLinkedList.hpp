#pragma once

#include "linkedList.hpp"

template <class Type>
class UnorderedLinkedList: public LinkedList<Type> {
    using LinkedList<Type>::head;
    using LinkedList<Type>::tail;
    using LinkedList<Type>::count;

    public:
        bool search(const Type& query) const;
        void insertFirst(Type* data);
        void insertLast(Type* data);
        void deleteNode(const Type& query);
};

#include "unorderedLinkedList.ipp"
