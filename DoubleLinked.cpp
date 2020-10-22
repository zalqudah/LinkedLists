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

void DoubleLinked::append(int ndat){
    Node* newNode = new Node(ndat);
    Node* iter = this->list;
    while(iter->next != NULL){
        iter = iter->next;
    }
    newNode->prev = iter;
    iter->next = newNode;
}

void DoubleLinked::insert(int loc, int ndat){
    if(list == NULL || loc == 0){
        push(ndat);
        return;
    }
    Node* newNode = new Node(ndat);
    Node* iter = this->list;
    for(int i = 0; i < loc-1; i++){
        iter = iter->next;
    }
    newNode->next = iter->next;
    newNode->prev = iter->prev;
    iter->next = newNode;
}

void DoubleLinked::replace(int loc, int ndat){
    if(list == NULL || loc == 0){
        push(ndat);
        return;
    }
    Node* iter = this->list;
    for(int i = 0; i < loc; i++){
        iter = iter->next;
    }
    iter->data = ndat;

}