#include <iostream>
#include <vector>

using namespace std;


//Variaveis globais: valores n e m, e o caminho
int n, m;

/* int checkSqr(int size){
    if(size <= n) return 1;
    return 0;
}
 */

vector<vector<int>> updateMatrix(vector<vector<int>> matrix, int col, int size) {
    for (int x = 0; x <= size-1; x++) {
        for (int y = 0; y <= size-1; y++) {
            matrix[x][col-y] = 0;
        }
    }
    /* for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 
    cout << "-------------------" << endl; */
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


int sum(vector<vector<int>> mat, vector<int> path) {
    if (mat.empty() || (int)mat.size() <= 1){
        return 1;
    }
    
    int col, size = 0;
    int count = 0;
    int rEmptied = 0;

    for(col = 0; col < path[0]; col++) {
        if (mat[0][col] == 0) break; 
        size++;
    }
    col--;
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
    newMat.erase(newMat.begin());
    path.erase(path.begin());
    return count + sum(newMat, path);
}





int main(){

    cin >> n;
    cin >> m;
    vector<int> path (n);

    int a;
    int count = 0;

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