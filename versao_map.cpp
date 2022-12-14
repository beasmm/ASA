#include <iostream>
#include <vector>
#include <map>

using namespace std;


//Variaveis globais: valores n e m, e o mapa com as matrizes já calculadas
int n, m;
map<vector<vector<int>>, long> umap;




vector<vector<int>> updateMatrix(vector<vector<int>> matrix, int col, int size) {
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            matrix[x][col-y] = 0;
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 
    cout << "-------------------" << endl;
    return matrix;
}


int rowsEmptied(vector<vector<int>> matrix) {
    int row, col;
    for(row = 0; row < (int)matrix.size(); row++) {
        for(col = 0; col < m; col++) {
            if (matrix[row][col] == 1){
                return row;
            }
        }
    }
    return row;
}


long sum(vector<vector<int>> mat, vector<int> path) {
    if (mat.empty() || (int)mat.size() <= 1) return 1;
    long total=0;
    long count = 0;
    int col, size = 0;
    int rEmptied = 0;
    if (umap.count(mat)!=0){
        return umap[mat];
    }
    for(col = 0; col < path[0]; col++) {
        if (mat[0][col] == 1) size++;
        if (size != 0 && mat[0][col] == 0) break; 
    }
    if (col != 0) col--;
    while (size >= 2) {
        if (size <= (int)mat.size()) {
            vector<vector<int>> newMat = updateMatrix(mat, col, size);
            vector<int> newPath = path;
            rEmptied = rowsEmptied(newMat);
            while (rEmptied > 0) {
                newMat.erase(newMat.begin());
                newPath.erase(newPath.begin());
                rEmptied--;
            }
            count += sum(newMat, newPath);       
        }
        
        size--;
    }   
    vector<vector<int>> newMat = updateMatrix(mat, col, size);
    if(col == 0 || rowsEmptied(newMat) != 0){
        newMat.erase(newMat.begin());
        path.erase(path.begin());
    } 
    total += count + sum(newMat, path);
    umap.insert({mat, total});
    return total;
}





int main(){

    cin >> n;
    cin >> m;
    vector<int> path (n);

    int a;
    long count = 0;

    //Inicialização da matriz de acordo com valores introduzidos
    vector<vector<int>> matrix(n, vector<int>(m));
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
        count = sum(matrix, path);
        cout << count << endl;
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