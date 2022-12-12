#include <iostream>
#include <vector>

using namespace std;


int maxSqr(int n_lines, vector<int> path){
    int maxArea = 1;

    for (int i = 0; i < n_lines; i++) {
        if (n_lines - (i+1) >= path[i] - 1) {
            maxArea = path[i];
        }
        else{
            for(int j = 2; j < path[i]; j++){
                if (n_lines - (i+1) >= j - 1 && maxArea < j){ 
                   maxArea = j;
                }
            }
        }
    }
    return maxArea;
}


//int isSquare(int line, int column) {
//    if (line * line == column * column) return 1;
//
//    return 0;
//}


int calcSq(int a) {
    if (a == 0) return 0;

    return a*a + calcSq(a-1);
}

int main() {
    int n, m, sq;
    int i, a;
    int out = 0;
    vector<int> v;


    cin >> n;
    cin >> m;


    for (i = 0; i < n; i++) {
        cin >> a;
        out += a;
        v.push_back(a);
    }


    if (out != 0){
        out = maxSqr(n, v);
    }

    cout << out  << endl;

    return 0;
}