#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

int check_relation(int prev_depth, int start, vector<bool>& visited);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // group
    bool is_printed = false;
    for (int s = 0; s < n; s++) {
        vector<bool> visited(n, false);
        if (check_relation(0, s, visited) >= 4) {
            cout << "1\n";
            is_printed = true; break;
        }
    }

    if (!is_printed) cout << "0\n";

    return 0;
}

int check_relation(int prev_depth, int start, vector<bool>& visited) {
    if (prev_depth >= 4) return prev_depth;

    visited[start] = true;
    
    int max_depth = prev_depth;
    for (int i = 0; i < adj[start].size(); i++) {
        if (visited[adj[start][i]]) continue;

        max_depth = max(
            max_depth, 
            check_relation(prev_depth+1, adj[start][i], visited)
        );
    }

    visited[start] = false;

    return max_depth;
}