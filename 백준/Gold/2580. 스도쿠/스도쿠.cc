#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef pair<int, int> pii;

vector<vector<int>> board(9, vector<int>(9, -1));
vector<pii> empty_loc;

bool is_printed = false;

void init();
void sudoku(int idx);
void print();
bool isPossible(int r, int c);

int main() {

    init();
    sudoku(0);

    return 0;
}

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> t;
            if (t == 0) empty_loc.push_back({i, j});
            board[i][j] = t;
        }
    }
}

void sudoku(int idx) {
    if (idx == empty_loc.size()) {
        print();
        return;
    }

    int r = empty_loc[idx].first, c = empty_loc[idx].second;

    for (int i = 1; i <= 9; i++) { // 넣을 숫자 확인
        if (is_printed) return;

        // 값 입력
        board[r][c] = i;
        if (!isPossible(r, c)) {
            board[r][c] = 0;
            continue;
        }

        sudoku(idx+1);
        board[r][c] = 0;
    }
}

bool isPossible(int r, int c) {
    for (int i = 0; i < 9; i++) {
        if (i != r && board[i][c] == board[r][c]) return false;
        if (i != c && board[r][i] == board[r][c]) return false;
    }

    int sdr = (r/3)*3, sdc = (c/3)*3;
    for (int i = 0; i < 9; i++) {
        int nr = sdr + (i/3), nc = sdc + (i%3);
        if (nr != r && nc != c && board[nr][nc] == board[r][c]) return false;
    }

    return true;
}

void print() {
    is_printed = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}