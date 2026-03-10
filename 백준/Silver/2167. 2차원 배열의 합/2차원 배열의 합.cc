#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> nums;

void input();

int main() {

    input();

    int r; cin >> r;
    for (int i = 0; i < r; i++) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;

        int sum = 0;
        for (int r = sr; r <= er; r++) {
            for (int c = sc; c <= ec; c++) {
                sum += nums[r-1][c-1];
            }
        }

        cout << sum << '\n';
    }

    return 0;
}

void input() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    nums = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
        }
    }
}