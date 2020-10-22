#ifndef DoubleLinked_HPP
#define DoubleLinked_HPP

#include "Node.hpp"

class DoubleLinked{
    private:
        Node* list;
    public:
        DoubleLinked();
        DoubleLinked(Node* node);
        ~DoubleLinked();

};

#endif