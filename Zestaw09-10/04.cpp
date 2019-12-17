#include <iostream>
using namespace std;

/*
4. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej elementów.
*/

struct node {
  int value;
  node *next;
};

node *reversed(node *list){
  node *prev = NULL;
  while(list != NULL){
    node *next = list->next;
    list->next = prev;
    prev = list;
    list = next;
  }
  return prev;
}

node *reversedRec(node *list){
// jezeli lista pusta to zwroc liste pusta
  if(list == NULL){
    return NULL;
  }
// jezeli lista jednoelementowa to zwroc ja
  if(list->next == NULL){
    return list;
  }

// rekursywnie odwroc reszte listy
  node *tail = reversedRec(list->next);
// zmien nexta nastepnego node'a na aktualny element (faktyczne odwracanie)
  list->next->next = list;
// zamien nexta aktualnego elementu na poprzednik (pierwszy to NULL, kolejnym ustawia poprzednia linijka)
  list->next = NULL;
// zwroc odwrocona reszte listy
  return tail;
}

// DEBUGING HELPERS BELOW

void print(node *to_print){
  while(true){
    if(to_print == NULL){
      cout << "NULL";
    }
    cout << to_print->value << "->";
    to_print = to_print->next;
  }
  cout << endl;
}

node *create(int arr[], int N){
  node *p, *tmp;
  p = new node;
  
  for(int i = 0; i < N; i++){
    p->value = arr[i];
    p->next = i == N-1 ? NULL : new node;

    if(i == 0){tmp = p;}

    p = p->next;
  }
  return tmp;
}

int main(){
  node *p1 = create((int[]){1,3,5,7}, 4);

  print(p1);
  print(reversed(p1));
}
