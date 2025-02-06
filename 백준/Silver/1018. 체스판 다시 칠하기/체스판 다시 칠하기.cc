#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int getCnt(vector<vector<int>> board, int i, int j, int start_v);

int main() {

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string tmp; int j = 0;
        cin >> tmp;
        for (char a: tmp) {
            board[i][j++] = (a == 'B') ? 1 : 0;
        }
    }

    int min_cnt = 2500;
    for (int i = 0; i <= N-8; i++) {
        for (int j = 0; j <= M-8; j++) {
            min_cnt = min(min_cnt, getCnt(board, i, j, 1));
            min_cnt = min(min_cnt, getCnt(board, i, j, 0));
        }
    }

    cout << min_cnt << endl;

    return 0;
}

int getCnt(vector<vector<int>> board, int ii, int ij, int start_v) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (
                board[ii+i][ij+j] != ((start_v+j+i)%2)
            ) cnt++;
        }
    }
    return cnt;
}