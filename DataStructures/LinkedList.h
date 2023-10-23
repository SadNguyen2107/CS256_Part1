#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <functional>
#include <iostream>

template <typename Value>
class LinkedList
{
private:
    Node<Value> *head;

public:
    LinkedList();
    ~LinkedList();

    // Return the Head Node of the LinkedList
    Node<Value> *getHead() { return this->head; };

    // Add a new node with given data to the end of the linked list
    void add(Value value_to_add);

    // Remove the node with value to delete
    void remove(std::function<bool(Value, Value)> isTrue, Value value_to_compare);

    //* DEBUG PURPOSE
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<Value> &linkedList)
    {
        Node<Value> *current_head = linkedList.head;

        int pos = 1;
        while (current_head != nullptr)
        {
            os << "[" << pos << "] " << current_head->data << '\n';
            current_head = current_head->next;
            pos++;
        }
        os << std::endl;

        return os;
    }
};

template <typename Value>
LinkedList<Value>::LinkedList()
{
    this->head = nullptr;
}

template <typename Value>
LinkedList<Value>::~LinkedList()
{
    while (head != nullptr)
    {
        Node<Value> *temp_node = this->head;
        this->head = this->head->next;
        delete temp_node;
    }
}

template <typename Value>
void LinkedList<Value>::add(Value value_to_add)
{
    // IF the linkedList don't have the head
    if (this->head == nullptr)
    {
        this->head = new Node<Value>(value_to_add);
    }
    else if (this->head->next == nullptr) // IF the LinkedList have the head
    {
        this->head->next = new Node<Value>(value_to_add);
    }
    else // If the linkedList have more than 2 element
    {
        Node<Value> *newNode = new Node<Value>(value_to_add);

        Node<Value> *current_head = this->head;
        while (current_head != nullptr)
        {
            current_head = current_head->next;
        }
        current_head->next = newNode;
    }
}

template <typename Value>
void LinkedList<Value>::remove(std::function<bool(Value, Value)> isTrue, Value value_to_compare)
{
    Node<Value> *prev_node = nullptr;
    Node<Value> *current_head = this->head;
    while (!isTrue(value_to_compare, current_head->data))
    {
        prev_node = current_head;
        // Loop until get the value
        current_head = current_head->next;
    }

    // If Found -> NOT NULL
    // ELSE -> NULL
    if (current_head != nullptr)
    {
        // If the node found is the head
        // IF the node found is not the head
        if (current_head == this->head)
        {
            delete current_head;
            this->head = nullptr;
        }
        else
        {
            prev_node->next = current_head->next;
            delete current_head;
        }
    }
}

#endif