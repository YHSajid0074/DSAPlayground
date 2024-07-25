#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class queue{
    public:
    node * front;
    node*back;
    queue(){
        back=nullptr;
        front=nullptr;
    }

    void push(int data){
        node * newnode=new node(data);
        if(front==nullptr){
            front=newnode;
            back=newnode;
        }
        back->next=newnode;
        back=newnode;
    }void pop(){
        node 
    }

};
