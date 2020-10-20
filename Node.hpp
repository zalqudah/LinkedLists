#ifndef Node_hpp
#define Node_hpp


class Node{
    public:
        int data;
        Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


#endif
