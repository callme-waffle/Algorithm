#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};

int n;

int getHomeCnt(int y, int x) {
    int cnt = 1;
    board[y][x] = 0;
    
    for (int i = 0; i < 4; i++) {
        int ny = y+dy[i], nx = x+dx[i];
        if ( !(
            ny >= 0 && nx >= 0 &&
            ny < n && nx < n
        ) ) continue;
        if (board[ny][nx]) cnt += getHomeCnt(ny, nx);
    }

    return cnt;
}

int main() {

    cin >> n;

    board = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < n; j++) {
            board[i][j] = (t[j] - '0');
        }
    }

    vector<int> counts;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) counts.push_back(getHomeCnt(i, j));
        }   
    }

    cout << counts.size() << '\n';
    sort(counts.begin(), counts.end());

    for (int count: counts) {
        cout << count << '\n';
    }

    return 0;
}