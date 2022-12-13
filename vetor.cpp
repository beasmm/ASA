#include <iostream>
#include <vector>

using namespace std;

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
int CheckSq(int val, int n){
    if(n-val >=0) return 1;
    return 0;
}



vector<int> Calcus(int n, int m, vector<vector<int>> mat){
    vector<int> vals(n-2, 0);
    int val = 0;


    for(int row = 0; col < n; i++){
        for(int col = 0; mat[row][col] == 0; col ++){
            val++;
        }

        for(val; )










    }















}






int main(){

    int n,m, a;

    //vector<int> poop;

    cin >> n;
    cin >> m;

    int N = n+1;
    int M = m+1;

    //Inicialização da matriz de acordo com valores introduzidos
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int i = 0; i < n; i++) {
        if (i != 0){
            cin >> a;
            for (int j = 0; j < a; j++) {
                matrix[i+1][j] = 1;
            }
        }
    }

    cout << n << endl;
    //poop = Calcus(n, m, matrix);


    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
   
    return 0;
}