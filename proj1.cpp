#include <iostream>
#include <vector>

using namespace std;


int isSquare(int line, int column) {
    if (line * line == column * column) return 1;

    return 0;
}


int calcSq(int a) {
    if (a == 0) return 0;

    return a*a + calcSq(a-1);
}

int main() {
    int line, column, sq;
    int i, a;
    int out = 0;
    vector<int> v;


    cin >> line;
    cin >> column;


    for (i = 0; i < line; i++) {
        cin >> a;
        out += a;
        v.push_back(a);
    }


    if (out != 0) (isSquare(line, column)) sq = calcSq(line);

    cout << out  << endl;

    return 0;
}