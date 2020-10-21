#ifndef SingleLinked_HPP
#define SingleLinked_HPP

#include "Node.hpp"
#include <iostream>

class SingleLinked{
    private:
        Node* list;

    public:
        //De/Constructors
        SingleLinked();
        SingleLinked(Node* l);
        ~SingleLinked();

        //Data io
        void append(int ndat);
        void push(int ndat);
        void insert(int loc, int ndat);
        void remove(int loc);
        int at(int loc);

        //Manips
        void reverse();
        Node* pop();
        void sublist(int from, int to);
        //Metrics
        int size();
        

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