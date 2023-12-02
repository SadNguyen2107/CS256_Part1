#ifndef NODE_H
#define NODE_H

template <typename Value>
struct Node
{
    Value data;
    Node* next;

    Node(Value data): data(data), next(nullptr) {}
    ~Node()
    {
        delete data;
    }
};


#endif