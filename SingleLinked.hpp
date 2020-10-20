#ifndef SingleLinked_HPP
#define SingleLinked_HPP

#include "Node.hpp"

class SingleLinked{
    public:
        Node* list;
    private:
        SingleLinked();
        ~SingleLinked();
        void append(/*Node** ref,*/ int ndat);
        //void push(Node** ref, int ndat);
        //void insertAfter(Node* prev, int ndat);
};


#endif;