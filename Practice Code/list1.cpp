//insert at first
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

node * insertAtFirst(node * head,int n){
node * newnode=new node(n);
newnode->next=head;
return newnode;
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

int n;
cin>>n;
   
   head=insertAtFirst(head,n);
   triverse(head);

}