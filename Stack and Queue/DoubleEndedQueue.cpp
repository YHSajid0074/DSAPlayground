#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node *prev;
    node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class deque{
    node *front, *back;
public:
    deque(){
        front = back = NULL;
    }
    void push_front(int x){
        node *n = new node(x);
        if(front == NULL){
            front = back = n;
            return;
        }
        n->next = front;
        front->prev = n;
        front = n;
    }

    void push_back(int x){
        node *n = new node(x);

        if(front == NULL){
            front = back = n;
            return;
        }

        back->next = n;
        n->prev = back;
        back = n;
    }

    void pop_front(){
        if(front == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == back){
            delete front;
            front = back = NULL;
            return;
        }

        node *todelete = front;
        front = front->next;
        front->prev = NULL;
        delete todelete;
    }

    void pop_back(){
        if(back == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        if(front == back){
            delete back;
            front = back = NULL;
            return;
        }

        node *todelete = back;
        back = back->prev;
        back->next = NULL;
        delete todelete;
    }

    int peek_front(){
        if(front == NULL){
            cout << "queue is empty" << endl;
            return 0;
        }
        return front->data;
    }

    int peek_back(){
        if(back==NULL){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return back->data;
    }

    bool empty(){
        return front==NULL;
    }
};

int main(){
    deque q;
    q.push_front(9087);
    q.push_front(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    cout<< "Front: " <<q.peek_front()<< endl;
    cout<< "Back: " <<q.peek_back()<< endl;
    q.pop_front();
    q.pop_back();
    cout<< "Front: "<<q.peek_front()<< endl;
    cout<< "Back: "<<q.peek_back()<< endl;

    return 0;
}
