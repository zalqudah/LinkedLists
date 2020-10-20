#include <iostream>
#include "SingleLinked.hpp"
#include "Node.hpp"

using namespace std;

SingleLinked::SingleLinked(){
    this->list = NULL;
}

SingleLinked::~SingleLinked(){
    delete this->list;
}

void SingleLinked::append(int ndat){
    Node* last = list;

    //build node to append
    Node* newNode = new Node();
    newNode->data = ndat;
    newNode->next = NULL;

    //will be first in list
    if(list == NULL){
        list = newNode;
        return;
    }
    //else
    //traverse to last node
    //assign this node to last pos
    while(last->next != NULL){
        last = last->next;
    }
    last->next = newNode;
    return;
}

void SingleLinked::push(int ndat){
    Node* last = this->list;

    Node* newNode = new Node();
    newNode->data = ndat;
    newNode->next = this->list;
    
    this->list = newNode;
}





