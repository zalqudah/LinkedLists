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
    last = newNode;

    this->list = last;
}

/*void SingleLinked::insert(int loc, int ndat){
    Node* temp = this->list;

    Node* newNode = new Node();
    newNode->data = ndat;

    if(this->list == NULL){
        newNode->next = NULL;
        this->list = newNode;
        return;
    }

    int iter = 0;
    while((temp->next != NULL) && (iter < loc-1)){
        temp = temp->next;
        iter++;
    }
    newNode->next = temp;
    temp->next = newNode;
}*/

Node* SingleLinked::Next(int loc){
    int iter = 0;
    while((list->next != NULL) && (iter < loc-1)){
        list = list->next;
        iter++;
    }
    return list->next;
}


