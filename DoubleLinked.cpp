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

DoubleLinked::DoubleLinked(const DoubleLinked &L){
    Node* NEXT = NULL;
    Node* CURR = NULL;
    if(L.list == NULL){
        this->list = NULL;
    }
    else{
        this->list = new Node();
        list->data = L.list->data;
        Node* HEAD = L.list;
        NEXT = L.list->next;
        CURR = this->list;
        while((NEXT != NULL) || (NEXT != HEAD)){
            CURR->next = new Node();
            CURR->data = NEXT->data;
            CURR = CURR->next;
            CURR->prev = NEXT->prev;
            NEXT = NEXT->next;
        }
        if(NEXT == HEAD){
            CURR->next = NULL;
        }
    }
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
    //Cant rip non-circular list
    if(isCircular() == false){
        return;
    }
    //0 is a special case
    if(loc == 0){
        this->list->prev->next = NULL;
        this->list->prev = NULL;
        return;
    }
    //All other locations
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

void DoubleLinked::shift(int i){
    if(!isCircular()){
        stitch();
        rip(i);
    }
    else{
        rip(i);
        stitch();
    }
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
