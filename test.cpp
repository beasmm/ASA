#include <iostream>
using namespace std;

int CalcSqr(int lin, int cal, int path[]){

    int Sqr = 0;

    for (int i =0; i < lin ; i++){

        if ((path[i] <= lin -1) && (Sqr < path[i]))
            Sqr = path[i];
        
        if ((lin -1 <= path[i]) && (Sqr < lin-1))
            Sqr = lin -1;
    }

    cout << "calcsqr: " << Sqr << endl;

    return Sqr;
}

int Cal(int lin, int cal, int path[], int sqr, int count){
    for (int i = 0; i <lin ; i++){
        for (int j = 0; j <= path[i]; j++){

            if((lin -1 >= sqr) && (path[i]- j >= sqr))
                count++;
        }

        if (((path[i]) / sqr >= 2) && (lin -1 >= sqr))
            count = count + (path[i] / sqr) + (path[i] * (path[i] % sqr));
    }
    return count;
}

int main(){

    int n, m;

    cin >> n;
    cin >> m;
    int path[20];

    for (int i =0; i < n; i++){
        cin >> path[i];
    }
    int c = Cal(n, m, path, CalcSqr(n,m,path), 1);

    cout << c << endl;
    return 0;
}