#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
long long b;
vector<vector<int>> counts;

pair<int, int> input();
int fill(int height);

int main() {
    auto v = input();
    priority_queue<pair<int, int>> pq;

    for (int height = v.first; height >= v.second; height--) {
        auto time = fill(height);
        if (time == -1) continue;
        pq.push({ -1 * time, height });
    }

    if (!pq.empty())
        cout << pq.top().first * -1 << ' ' << pq.top().second << '\n';

    return 0;
}

pair<int, int> input() {
    cin >> n >> m >> b;
    counts = vector<vector<int>>(n, vector<int>(m));
    
    int max_v = 0, min_v = 300;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> counts[i][j];
            max_v = max(max_v, counts[i][j]);
            min_v = min(min_v, counts[i][j]);
        }
    }

    return { max_v, min_v };
}

int fill(int height) {
    int time = 0, need = 0;
    for (vector<int> count: counts) {
        for (int blocks: count) {
            int nc = (height-blocks);
            need += nc;
            if (nc > 0) time += nc;
            else time -= (nc*2);
        }
    }

    if (need <= b) return time;
    return -1;
}