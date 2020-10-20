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
        void push(int ndat);
       // void insert(int loc, int ndat);
        Node* Next(int loc);

        friend std::ostream &operator<< (std::ostream &out, const SingleLinked &L){
            int n = 0;
            Node* ll = L.list;
            while(ll != NULL){
                out << ll->data << " ";
                ll = ll->next;
                n++;
            }
            out << std::endl;
            out << "list len: " << n << std::endl;
            return out;
        }
};


#endif