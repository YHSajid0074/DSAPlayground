#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node * prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void insertAtFirst(node * & head,int data){
    node * n=new node(data);
    n->next=head;

    if(head!=NULL){
        head->prev=n;
       
    }
head=n;
}
void insertAtLast(node * & head,int data){
    node * temp=head;
    node *n=new node(data);
    if(head==NULL){
head=n;
return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;

}

void display(node * head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}

int main(){
    node * head=NULL;

    insertAtLast(head,1);
insertAtLast(head,3);
insertAtLast(head,5);
insertAtLast(head,9);
    insertAtFirst(head,13);


display(head);

}