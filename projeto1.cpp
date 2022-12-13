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
    for (int x = 0; x <= size-1; x++) {
        for (int y = 0; y <= size-1; y++) {
            matrix[x][y] = 0;
        }
    }
    return matrix;
}


int rowsEmptied(vector<vector<int>> matrix) {
    int row, col;
    for(row = 0; row < n; row++) {
        for(col = 0; col < m; col++) {
            if (matrix[row][col] == 1)
                col = m + 1;
        }
        if (col == m + 1) return row;
    }
    return 0;
}


int sum(int row, vector<vector<int>> mat, vector<int> path) {
    if (row >= n) return 1;

    int col, size = 0;
    int count = 0;

    for(col = 0; col < path[row]; col++) {
        if (mat[row][col] == 1) size++;
    }

    while (size >= 2) {
        if (checkSqr(size, row) == 1) {
            vector<vector<int>> newMat = updateMatrix(mat, row, col, size);
            count += sum(row + rowsEmptied(newMat), newMat, path);
        }
        size--;
    }
    vector<vector<int>> newMat = updateMatrix(mat, row, col, size);

    return count + sum(row + rowsEmptied(newMat), newMat, path);
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