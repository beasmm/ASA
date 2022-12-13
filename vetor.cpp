#include <iostream>
#include <vector>

using namespace std;


//Variaveis globais: valores n e m, e o caminho
int n, m;
vector<int> path;

/*
vector<int> Calcus(int n, int m, vector<vector<int>> mat){
    vector<int> vals(n-2, 0);


    for(int row = n-1; row > 0; row--){
        for(int col = m-1; col > 0; col--){
            if(mat[row][col] >= 1) {
                if (mat[row+1][col] == mat[row][col+1] == mat[row+1][col+1]){
                    mat[row][col]++;
                    vals[mat[row][col]-2]++;
                }
            
                else {
                    mat[row][col] = max(mat[row+1][col], mat[row][col+1]);
                    vals[mat[row][col]-2]++;
                }
            }
        }
    }
    

    return vals;
}*/

/* vector<int> Calcus(int n, int m, vector<vector<int>> mat, vector<int> path){
    vector<int> vals(n-2, 0);
    int check = 0;

    if ()

    
    for(int row = 0; row < n; row++){
        for(int col = 0; col == path[row]; col ++){
            if(mat[row][col])check++;
        }

        for(check; check > 0; check--){
            if(CheckSq(check, n)){

            }



        }
    }

} */


int checkSqr(int size, int row){

    if(row + size <= n) return 1;

    return 0;
}


vector<vector<int>> updateMatrix(vector<vector<int>> matrix, int row, int col, int size) {
    for (int x = size - 1; x >= 0; x--) {
        matrix[row+size][col];
    }
    for (int y = size - 1; y >= 0; y--) {
        matrix[row][col+y];
    }
    return matrix;
}


int rowsEmptied(vector<vector<int>> matrix) {
    int count = 0;

    

    return count;
}


int sum(int row, vector<vector<int>> mat) {
    if (row == n) return 1;

    int col, size = 0;

    for(col = 0; col < path[row]; col++) {
        if (mat[row][col] == 1) size++;
    }

    while (size >= 2) {
        if (checkSqr(size, row)) {
            vector<vector<int>> newMat = updateMatrix(mat, row, col, size);

            row + rowsEmptied(newMat);

            if (col == path[row]) row++;

            return 1 + sum(row, newMat);
        }
    }

    return sum(row + 1, updateMatrix(mat, row - 1, col - 1, 1));
}





int main(){

    cin >> n;
    cin >> m;

    int a, count = 0;
    int N = n+1;
    int M = m+1;

    //Inicialização da matriz de acordo com valores introduzidos
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < n; i++) {
        if (i != 0){
            cin >> a;
            count += a;
            path[i] = a;
            for (int j = 0; j < a; j++) {
                matrix[i+1][j] = 1;
            }
        }
    }


/* 
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
    */
    return 0;
}