#include <iostream>

using namespace std;

typedef struct {
    int line;
    int column;
} Table;


int isSquare(Table t) {
    if (t.line * t.line == t.column * t.column) return 1;

    return 0;
}


int calcSq(int a) {
    if (a == 0) return 0;

    return a*a + calcSq(a-1);
}

int main() {
    Table t;
    int sq;

    cin >> t.line;
    cin >> t.column;

    if(isSquare(t)) sq = calcSq(t.line);

    return 0;
}