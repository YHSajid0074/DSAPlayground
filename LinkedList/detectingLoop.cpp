#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        next=NULL;
    }
};
void print(node * head){
    node* temp=head;
    node* hare=head;
    node * tortle=head;
    while (hare !=NULL ){
        hare=hare->next->next;
        tortle=tortle->next;
        if(hare == tortle){
            cout<<"loop detected";
            break;
            
        }
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
   second1->next=head;

   print(head);
}