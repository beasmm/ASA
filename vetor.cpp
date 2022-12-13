#include <iostream>
#include <vector>

using namespace std;


//Variaveis globais: valores n e m, e o caminho
int n, m;

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
    int row, col;
    for(row = 0; row < n; row++) {
        for(col = 0; col < m; col++) {
            if (matrix[row][col] == 1)
                col = m;
        }
        if (col == m) break;
    }
    return row;
}


int sum(int row, vector<vector<int>> mat, vector<int> path) {
    if (row == n) return 1;

    int col, size = 0;

    for(col = 0; col < path[row]; col++) {
        if (mat[row][col] == 1) size++;
    }

    while (size >= 2) {
        if (checkSqr(size, row)) {
            vector<vector<int>> newMat = updateMatrix(mat, row, col, size);
            row += rowsEmptied(newMat);

            return 1 + sum(row, newMat, path);
        }
        size--;
    }
    vector<vector<int>> newMat = updateMatrix(mat, row, col, size);
    row += rowsEmptied(newMat);

    return sum(row, newMat, path);
}





int main(){

    cin >> n;
    cin >> m;
    vector<int> path (n);

    int a;
    int count = 0;
    int N = n+1;
    int M = m+1;


    //Inicialização da matriz de acordo com valores introduzidos
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < n; i++) {
        cin >> a;
        count += a;
        path[i] = a;
        for (int j = 0; j < a; j++) {
            matrix[i][j] = 1;
        }
    }

    if (count == 0) cout << 0 << endl;

    else {
        count = sum(0, matrix, path);
        cout << count << endl;
    }
    /* 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } */
    
    return 0;
}