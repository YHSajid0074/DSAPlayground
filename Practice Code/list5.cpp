//delete from last//

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void deleteAtlast(node * head){

node* temp=head;
while(temp->next->next !=NULL){
    temp=temp->next;
}
temp->next=NULL;


}


void triverse(node *head){
    node * temp=head;
    while(temp !=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

int main(){
   node * head=new node(5) ;
   node * first=new node(8);
   node * second =new node(9);


   head-> next=first;

   first->next=second;
  
   second->next=NULL;


   
 deleteAtlast(head);
   triverse(head);
   
}