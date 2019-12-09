/*
2. Zastosowania listy do implementacji tablicy rzadkiej. Proszę napisać
trzy funkcje:
- void init(node *&tab) – inicjalizującą tablicę,
- int value(node *tab, int n) – zwracającą wartość elementu o indeksie n,
- void set(node *&tab, int n, int value) – postawiającą wartość value pod
indeks n.
*/
#include <iostream>

struct node {
  node *next;
  int index;
  int value;
};

/*
  Idk why we need that ¯\_(ツ)_/¯
*/
void init(node *&tab){
}

node *new_last_node(int n, int v){
  node *created = new node();
  created->value = v;
  created->index = n;
  created->next = NULL;

  return created;
}

/*
Returns value of given index if exist, -1 otherwise.
Assumes tab is properly terminated linked list.
*/
int value(node *tab, int n){
  for(; tab != NULL; tab = tab->next){
    if(tab->index == n){
      return tab->value;
    }
  }
  
  return -1;
}

/*
Sets the new value to existing node with given index `n` or creates new node with that index and value.
*/
void set(node *&tab, int n, int value){
  node *list = tab;
  while(
    list != NULL and 
    list->next != NULL and 
    list->index != n
  ){
    list = list->next;
  }
  // if empty
  if(tab == NULL){
    tab = new_last_node(n, value);
    return;
  }

  // if we found node with given index
  if(list->index == n){
    list->value = value;
    return;
  }

  // if we didn't find node with given index
  if(list->next == NULL){
    list->next = new_last_node(n, value);
  }
}


//helpers
const int N = 4;
node* create_linked_list(int t[N]){
  node *list = new node();
  list->value = 0;
  list->index = t[0];

  node *first = list;
  for(int i = 1; i < N; i++){
    list->next = new node();
    list = list->next;
    list->index = t[i];
    list->value = i;
  }
  list->next = NULL;

  return first;
}

int main() {
  int t[N] = {2, 1, 3, 7};
  node *list = create_linked_list(t);
  node *clear = new node;

  set(clear, 1, 420);

  std::cout << value(clear, 1) << std::endl;
  std::cout << value(list, 7) << std::endl;
}
