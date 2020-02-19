//WIET interview question by Lord Icon

//zadanie, które Lord Icon daje studentom, którzy chcą się przepisać na WIET

//Na podstawie dwuwymiarowej tablicy bool t[N][N] odtworzyć strukturę wskaźnikową taką, że:
// - każdemu node'owi w strukturze odpowiada jedynka w tablicy bool
// - każdy node wskazuje na następny node w tym samym wierszu i kolumnie lub na NULL, gdy jest ostatni
// - struktura posiada tablice wartowników node * col[N] oraz node * row[N]
// - każdy z wartowników z col wskazuje na pierwszy element w danej kolumnie
// - każdy z wartowników z row wskazuje na pierwszy element w danym wierszu 

struct node{
    node *right;
    node *down;
};

node * col[N];
node * row[N];

bool t[N][N];

void func(node* row[N], node* col[N], bool t[N][N]){
    for (int i=0; i<N; i++) row[i]=col[i]=NULL;
    for (int c=N-1; c>=0; --c){
        for (int r=0; r<N; r++){
            if (t[r][c]){
                node *newEl=new node;
                
                newEl->down=col[c];
                col[c]=newEl;

                newEl->right=row[c];
                row[c]=newEl;
            }
        }
    }
}