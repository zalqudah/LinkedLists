#include <iostream>
#include "Node.hpp"
#include "DoubleLinked.hpp"

using namespace std;

DoubleLinked::DoubleLinked(){
    this->list = NULL;
}

DoubleLinked::DoubleLinked(Node* node){
    this->list = new Node();
    this->list->data = node->data;
    this->list->prev = NULL;
    this->list->next = NULL;
}

DoubleLinked::~DoubleLinked(){
    delete this->list;
}

void DoubleLinked::push(int ndat){
    Node* newNode = new Node(ndat);
    newNode->next = this->list;
    newNode->prev = NULL;
    if(this->list != NULL)
        this->list->prev = newNode;
    this->list = newNode;
}

void DoubleLinked::replace(int loc, int ndat){
    if(list == NULL || loc == 0){
        push(ndat);
        return;
    }
    Node* temp = this->list;
    for(int i = 0; i < loc; i++){
        temp = temp->next;
    }
    temp->data = ndat;

}