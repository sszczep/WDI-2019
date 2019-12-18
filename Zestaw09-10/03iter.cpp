#include <iostream>

using namespace std;

struct node{
    int data=0;
    node* next=NULL;
};


node* merge(node* a, node* b){
    if (a==NULL and b==NULL) return;
    if (a==NULL) return b;
    if (b==NULL) return a;

    node* head;

    if(a->data < b->data){
        head = a;
        a=a->next;}
    else{
        head = b;
        b=b->next;
    }
    
    node* tail=head;

    while(a!=NULL and b!=NULL){
        if(a->data < b->data){
            tail->next = a;
            tail=tail->next;
            a=a->next;}
        else{
            tail->next = b;
            tail=tail->next;
            b=b->next;}
        }        
    }

    if(a!=NULL){
        tail->next=a;
    }
    else if (b!=NULL){
        tail->next=b;
    }

    return head;
}
