#include <iostream>

using namespace std;

struct node{
    int data=0;
    node* next=NULL;
};

//odwracanie kolejności w liście
void reverse(node* &head){
    if(head==NULL or head->next==NULL) return;
    
    node* item=head;
    node* prev=NULL;

    do{
        node* next=item->next;
        item->next=prev;
        prev=item;
        item=next;
    }while (item!=NULL);
    head=prev;
}

int main(){
    node *a= new node;
    node *b= new node;
    node *c= new node;
    a->data=1;
    b->data=2;
    c->data=3;
    a->next=b;
    b->next=c;
    node *item = a;
    while (item!=NULL){
        cout<<item->data<<" ";
        item=item->next;
    }
    cout<<endl;
    reverse(a);
    item = a;
    while (item!=NULL){
        cout<<item->data<<" ";
        item=item->next;
    }    
    return 0;
}
