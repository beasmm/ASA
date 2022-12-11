#include <iostream>

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
    int line;
    int column;
    int sq;

    cin >> line;
    cin >> column;

    if(isSquare(line, column)) sq = calcSq(line);

    return 0;
}