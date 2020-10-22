#ifndef DoubleLinked_HPP
#define DoubleLinked_HPP

#include <iostream>
#include "Node.hpp"

class DoubleLinked{
    private:
        Node* list;
    public:
        DoubleLinked();
        DoubleLinked(Node* node);
        ~DoubleLinked();

        void push(int ndat);
        void append(int ndat);
        void replace(int loc, int ndat);
        void insert(int loc, int ndat);

        friend std::ostream &operator<< (std::ostream &out, const DoubleLinked &L){
            Node* ll = L.list;
            while(ll != NULL){
                out << ll->data << " ";
                ll = ll->next;
            }
            out << std::endl;
            //out << "list len: " << std::endl;
            return out;
        }
};

#endif