#include <iostream>
#include "Node.hpp"
#include "DoubleLinked.hpp"

using namespace std;

DoubleLinked::DoubleLinked(){
    this->list = NULL;
    //this->length = -1;
}

DoubleLinked::DoubleLinked(Node* node){
    this->list = new Node();
    this->list->data = node->data;
    this->list->prev = NULL;
    this->list->next = NULL;
    //this->length = -1;
}

DoubleLinked::~DoubleLinked(){
    delete this->list;
}

void DoubleLinked::push(int ndat){
    Node* newNode = new Node(ndat);
    Node* temp = this->list;
    Node* end = this->list;
    while(end != NULL){
        end = end->next;
        if((end != NULL) && (end->next == this->list)){
            end->next = newNode;
            temp->prev = newNode;
            break;}
    }
    newNode->next = temp;
    newNode->prev = end;
    if(this->list != NULL)
        temp->prev = newNode;
    this->list = newNode;
}

void DoubleLinked::append(int ndat){
    Node* newNode = new Node(ndat);
    Node* iter = this->list;
    Node* head = this->list;
    while((iter->next != NULL) && (iter->next != head)){
        iter = iter->next;
    }
    if(iter->next == head){
        newNode->next = head;
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

void DoubleLinked::stitch(){
    Node* iter = this->list;
    Node* head = this->list;
    //int count = 0;
    while(iter!=NULL){
        iter = iter->next;
        //count++;
        if(iter->next == NULL){break;}
    }
    head->prev = iter;
    iter->next = head;
    //this->length = count+1;
}

void DoubleLinked::rip(int loc){
    if(isCircular() == false){
        return;
    }
    Node* iter = this->list;
    Node* cursor = NULL;
    for(int i = 0; i < loc; i++){
        cursor = iter;
        iter = iter->next;
    }
    cursor->next = NULL;
    iter->prev = NULL;
    this->list = iter;
}

bool DoubleLinked::isCircular(){
    Node* temp = this->list;
    Node* head = this->list;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp == head){return true;}
    }
    return false;
}