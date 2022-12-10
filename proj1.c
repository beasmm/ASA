#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int line;
    int column;
} Table;



int isSquare(Table t){
    if (t.line*t.line ==  t.column*t.column) return 1;
    return 0;
}

int calcSq(int a){
    if (a == 0) return 0;
    return a*a + calcSq(a-1);
}


int main(){
    Table t;
    int sq; 
    scanf("%d", &t.line);
    scanf("%d", &t.column);
    if(isSquare(t)) sq =calcSq(t.line);

    //cada linha vai ter o numero de quadrados correspondente ao numero indicado
    //tentar dividir o espaco total em quadrados mais pequenos para usar calSq




    printf("%i\n", sq);
    return 0;
}