#include <iostream>
#include "SingleLinked.hpp"
#include "Node.hpp"

using namespace std;

SingleLinked::SingleLinked(){
    this->list = NULL;
}

SingleLinked::SingleLinked(Node* l){
    this->list = l;
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

void SingleLinked::insert(int loc, int ndat){
   if(loc == 0){
		push(ndat);
		return;
	}

	Node* temp = list;
	Node* newNode = new Node(ndat);
	for(int i = 0; i < loc-1; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;
}

void SingleLinked::remove(int loc){
	if(this->list == NULL)
        return;

    if(loc == 0){
        this->list = this->list->next;
        return;
    }
    Node* temp = list;
	Node* newNode = new Node();
	for(int i = 0; i < loc-1; i++){
		temp = temp->next;
	}
	newNode = temp->next->next;
	temp->next = newNode;
	return;

}

int SingleLinked::size(){
    Node* temp = this->list;
    int iter = 1;
    while(temp->next != NULL){
        iter++;
        temp = temp->next;
    }
    return iter;
}

Node* SingleLinked::pop(){
    Node* out = new Node();
    if(this->list == NULL)
        return out;
    if(size()-1 <= 0){
        this->list = NULL;
        return out;
    }
    Node* temp = this->list;
    for(int i = 0; i < size()-2; i++){
        temp = temp->next;
    }
    out->data = temp->next->data;
    out->next = NULL;
    temp->next = NULL;
    return out;
}

void SingleLinked::reverse(){
    Node* curr = list;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list = prev;

    //Look idk either but it works
}

Node* SingleLinked::Next(int loc){
    int iter = 0;
    Node* temp = list;
    while((temp->next != NULL) && (iter < loc-1)){
        temp = temp->next;
        iter++;
    }
    return temp->next;
}

void SingleLinked::DeleteAfter(int loc){
    int iter = 0;
    while((list->next != NULL) && (iter < loc-1)){
        list = list->next;
        iter++;
    }
    list->next = NULL;
}

