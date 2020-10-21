#ifndef SingleLinked_HPP
#define SingleLinked_HPP

#include "Node.hpp"
#include <iostream>

class SingleLinked{
    private:
        Node* list;
        Node* Next(int loc);
        void DeleteAfter(int loc);
    public:
        SingleLinked();
        SingleLinked(Node* l);
        ~SingleLinked();
        void append(int ndat);
        void push(int ndat);
        void insert(int loc, int ndat);
        void remove(int loc);
        int size();
        Node* pop();

        friend std::ostream &operator<< (std::ostream &out, const SingleLinked &L){
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