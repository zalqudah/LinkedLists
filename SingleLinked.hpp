#ifndef SingleLinked_HPP
#define SingleLinked_HPP

#include "Node.hpp"

class SingleLinked{
    private:
        Node* list;
    public:
        SingleLinked();
        ~SingleLinked();
        void append(int ndat);
        //void push(Node** ref, int ndat);
        //void insertAfter(Node* prev, int ndat);
};


#endif