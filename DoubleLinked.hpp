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
        DoubleLinked(const DoubleLinked &L);
        ~DoubleLinked();

        void push(int ndat);
        void append(int ndat);
        void replace(int loc, int ndat);
        void insert(int loc, int ndat);

        void stitch(); //Converts to circular list
        void rip(int loc); //Will only rip circular lists
        void shift(int i);

        bool isCircular();

        Node* Get();

        /*DoubleLinked operator+ (const int& i){
            DoubleLinked ll = DoubleLinked(this->list);
            //ll.shift(i);
            return ll;
        }*/

        friend std::ostream &operator<< (std::ostream &out, const DoubleLinked &L){
            Node* ll = L.list;
            Node* head = L.list;
            while(ll != NULL){
                out << ll->data << " ";
                ll = ll->next;
                if(ll == head){break;}
            }
            out << std::endl;
            //out << "list len: " << std::endl;
            return out;
        }
};

#endif