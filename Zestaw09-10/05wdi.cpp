struct node{
    int val;
    node* next;
}

node *order (node* list){
    node* f[10];
    node* l[10];
    for (int i=0; i<10; i++) f[i]=l[i]=null;
    while(list!=null){
        int idx=(list->val)%10;
        if(f[idx]==null)
            f[idx]=l[idx]=list;
        else
            l[idx]=l[idx]->next=list;
        list=list->next;
    }
    node* result=null;
    node* last=null;

    for (int i=0; i<10; i++){
        if (f[i]!=null){
            if (result==null) result=f[i];
            else last->next=f[i];
            last=l[i];
        }
    }

    /*
    result=null;
    for (int i=9;i>=0;i--)
        if (f[i]!=NULL){
            l[i]->next=result;
            res=f[i];
        }
    */

    return result;
}
