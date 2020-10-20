#ifndef SingleLinked_HPP
#define SingleLinked_HPP

#include "Node.hpp"
#include <iostream>

class SingleLinked{
    private:
        Node* list;
    public:
        SingleLinked();
        ~SingleLinked();
        void append(int ndat);
        //void push(Node** ref, int ndat);
        //void insertAfter(Node* prev, int ndat);
        friend std::ostream &operator<< (std::ostream &out, SingleLinked &L){
            while(L.list != NULL){
                out << L.list->data << " ";
                L.list = L.list->next;
            }
            out << std::endl;
            return out;
        }
};


#endif