#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<bool>> is_star;

int getCount(int n);
void decidePrint(int size, int r, int c);
void printStart();

int main() {
    int n;
    cin >> n;    
    is_star.resize(n, vector<bool>(n, false));

    n = getCount(n);
    decidePrint(n, 0, 0);

    printStart();
    
    return 0;
}

int getCount(int n) {
    if (n == 1) return 0;
    return 1 + getCount(n/3);
}

void decidePrint(int size, int r, int c) {
    if (size == 0) {
        is_star[r][c] = true;
        return;
    }

    int inc = pow(3, size-1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // i와 j가 중간위치인 경우 pass
            if (i == j && i == 1) continue;

            decidePrint(
                size-1,
                r + inc * i,
                c + inc * j
            );
        }
    }
}

void printStart() {
    for (vector<bool> row: is_star) {
        for (bool column: row)
            if (column) cout << "*";
            else cout << " ";

        cout << '\n';
    }
}