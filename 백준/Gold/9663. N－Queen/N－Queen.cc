#include <iostream>
#include <vector>

using namespace std;
vector<int> unavail(8);

int cnt = 0, n;

void dpQueen(int row);

int main() {
    cin >> n;

    unavail = vector<int>(n, -1);
    dpQueen(0);

    cout << cnt << '\n';

    return 0;
}

void dpQueen(int row) {
    if (row == n) {
        cnt++;
        return;
    }

    for (int col = 0; col < n; col++) {
        // 1. 열 체크
        if (unavail[col] != -1) continue;

        // 2. 대각선 체크
        bool is_cross_avail = true;
        
        for (int i = 1; i < n; i++) {
            if (col-i < 0 && col+i >= n) break;
            if ( col-i >= 0 && col-i < n ) {
                if (row-i >= 0)
                    if (unavail[col-i] == row-i)
                        is_cross_avail = false;

                if (unavail[col-i] == row+i)
                    is_cross_avail = false;
            }
            if ( col+i >= 0 && col+i < n ) {
                if (row-i >= 0)
                    if (unavail[col+i] == row-i)
                        is_cross_avail = false;
                    
                if (unavail[col+i] == row+i)
                    is_cross_avail = false;
            }
        }

        if (!is_cross_avail) continue;

        // 배치
        unavail[col] = row;
        
        dpQueen(row+1);
        
        // 배치 해제
        unavail[col] = -1;
    }
}