#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e;
    cin >> v >> e;

    vector<bool> visited(v, false);
    vector<vector<int>> adj(v, vector<int>());

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // 탐색
    int cnt = 0;
    for (int s = 0; s < v; s++) {
        if (visited[s] == 1) continue;

        queue<int> visitable;
        visitable.push(s);

        while(!visitable.empty()) {
            int v = visitable.front(); visitable.pop();
            if (visited[v]) continue;

            visited[v] = true;


            for (int node: adj[v]) {
                if (visited[node]) continue;
                visitable.push(node);
            }
        }

        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}