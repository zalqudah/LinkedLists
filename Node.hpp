#ifndef Node_hpp
#define Node_hpp


class Node{
    public:
        int data;
        Node* next;
    Node(){
        this->data = 0;
        //this->next = NULL; // Broke the code
    }
    Node(int data){
        this->data = data;
        //this->next = NULL; //Broke the code
    }
};


#endif
