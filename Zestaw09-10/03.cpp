#include <iostream>
using namespace std;

/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.


merge jest niszczace dla list, mergeRecursive nie (pierwsze mozna latwo naprawic tworzac nowego node'a)
*/

struct node {
  int value;
  node *next;
};

node *merge(node *&A, node *&B){
  node *root = new node();
  node *tail = root;

  while(true) {
    if(A == NULL){
      tail->next = B;
      break;
    }
    if(B == NULL){
      tail->next = A;
      break;
    }

    // obie niepuste
    if(A->value <= B->value){
      tail->next = A;
      A = A->next;
      tail = tail->next;
    } else {
      tail->next = B;
      B = B->next;
      tail = tail->next;
    }
  }

  return root->next;
}


node *_mergeRecursive(node *tail, node *A, node *B){
  if(A == NULL){
    return B;
  }
  if(B == NULL){
    return A;
  }

  tail = new node;
  if(A->value <= B->value){
    tail->value = A->value;
    tail->next = _mergeRecursive(tail->next, A->next, B);
  } else {
    tail->value = B->value;
    tail->next = _mergeRecursive(tail->next, A, B->next);
  }
  return tail;
}

node *mergeRecursive(node *A, node *B){
  return _mergeRecursive(new node, A, B);
}

// DEBUGING HELPERS BELOW

void print(node *to_print){
  if(to_print == NULL){
    cout << "empty list" << endl;
    return;
  }
  while(to_print != NULL){
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
  node *p2 = create((int[]){2,4,6,7}, 4);

  print(p1);
  print(p2);

  print(mergeRecursive(p1, p2));
  cout << endl;
  print(mergeRecursive(NULL, NULL));
  cout << endl;
  print(mergeRecursive(
    create((int[]){2}, 1),
    create((int[]){1}, 1)
  ));

  cout << endl;
  print(p1);
  print(p2);
}
