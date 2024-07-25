#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int data1){
       data =data1;
    }
};
 void print(node * head){
    node * temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
 }
void detect(node * head){
    node * first=head;
    node* second=head;

    while(second->next!= NULL && second->next->next !=NULL){
        first=first->next;
        second=second->next->next;
        if(first==second){
            break;
        }
    }

    first=head;
  //  while(first->next !=second->next){
   //     first=first->next;
   //     second=second->next;;
   // }
   // second->next=NULL;

}


int main(){
    node * head =new node(1);
      node * first =new node(2);
        node * second =new node(4);
          node * third =new node(5);
            node * forth =new node(7);
              node * fifth =new node(11);
                node * sixth=new node(3);


         head->next=first;
         first->next=second;
         second->next=third;
         third->next=forth;
         forth->next=fifth;
         fifth->next=sixth;
         sixth->next=NULL;

      //   print(head)   ;  
        detect(head)  ;
         cout<<endl;
          print(head)   ;  


}