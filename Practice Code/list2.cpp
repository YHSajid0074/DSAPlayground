//insert after a given node
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

void  insertAtmid(node * head,int n,int m){
node * newnode=new node(m);
node* temp=head;
while(temp->data != n){
temp=temp->next;
}
newnode->next=temp->next;
temp=newnode;

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

int n,m;
cin>>n>>m;
   
   insertAtmid(head,n,m);
   triverse(head);
   
}