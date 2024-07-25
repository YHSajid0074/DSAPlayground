#include<iostream>
using namespace std;

class node {
    public :
    int data;
    node * next;
    node * prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};


void insertATlast(node*& head,int data){
node * n=new node(data);
    if(head==NULL){
      head=n;
      return;
    }
    
    node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
temp->next=n;
n->prev=temp;

}


void insertATfirst(node * &head,int data){
   node * n= new node(data);
   n->next=head;
   if(head!=NULL){
    head->prev=n;
   }
   head=n;

}

void display(node* head){
    node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
node * head=NULL;
insertATlast(head,1);
insertATlast(head,3);
insertATlast(head,5);
insertATlast(head,9);
insertATfirst(head,13);

display(head);

}