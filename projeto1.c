#include <stdlib.h>
#include <stdio.h>


int line, column;

int main(){
    //scanf("%d", &line);
    //scanf("%d", &column);
    int tiles[line], n;
    for(int i = line; i > 0; i--){
        scanf("%d", &n);
        tiles[i] = n;
    }

    for(int i = 0; i< line; i++){
        int n = tiles[i];
        printf("%d", n);
    }
    
    //olá a bea esteve aqui!!!!!!!!!!!!!!!!!!!!!!
    teste1();


    return 0;
}
//asdasdasdasd

int aumenta(){
    return 45;
}