//deleting a perticular node//

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

node* deletePerticular(node * head,int n){
if(head->data==n){
   return  head->next;
}
node*temp=head;
node*prev=NULL;
while(temp->data !=n){
    prev=temp;
    temp=temp->next;
}
prev->next=temp->next;
return head;
}


void triverse(node *head){
    node * temp=head;
    cout<<"The values are :";
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
   node * head=new node(5) ;
   node * first=new node(8);
   node * second =new node(9);
  node * head1=new node(11) ;
   node * first1=new node(19);
   node * second1=new node(38);

   head-> next=first;

   first->next=second;
   head1-> next=first1;

   first1->next=second1;
second->next=head1;
   second1->next=NULL;

int n;
cin>>n;
   
 head =deletePerticular(head,n);
   triverse(head);
   
}