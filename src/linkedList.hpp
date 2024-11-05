#pragma once

template <class Type>
struct Node {
    Type* data;
    Node<Type>* next;
};

template <class Type>
class LinkedListIterator {
    private:
        Node<Type>* current;

    public:
        LinkedListIterator();
        LinkedListIterator(Node<Type>* node);
        Type operator*();
        LinkedListIterator<Type> operator++();
        bool operator==(const LinkedListIterator<Type>& right) const;
        bool operator!=(const LinkedListIterator<Type>& right) const;
};

template <class Type>
class LinkedList {
    public:
        LinkedList();
        LinkedList(const LinkedList<Type>& other);
        ~LinkedList();

        LinkedList<Type>& operator=(const LinkedList<Type>& other);
        void initializeList();
        bool isEmptyList() const;
        void print() const;
        int length() const;
        void destroyList();
        Type front() const;
        Type back() const;
        virtual bool search(const Type& query) const = 0;
        virtual void insertFirst(Type* data) = 0;
        virtual void insertLast(Type* data) = 0;
        virtual void deleteNode(const Type& query) = 0;
        LinkedListIterator<Type> begin();
        LinkedListIterator<Type> end();
    
    protected:
        int count;
        Node<Type>* head;
        Node<Type>* tail;
    
    private:
        void copyList(const LinkedList<Type>& other);
};

#include "linkedList.ipp"
