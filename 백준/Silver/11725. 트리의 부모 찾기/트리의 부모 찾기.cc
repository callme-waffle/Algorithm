#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; // 노드의 개수
vector<vector<int>> adj; // 인접리스트
vector<int> parent; // 각 노드의 부모

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    adj.resize(n+1);
    parent.resize(n+1, -1);

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent[1] = 1;
    queue<int> que; // 방문예정지
    que.push(1);

    while(!que.empty()) {
        int cur = que.front(); que.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];

            // nxt를 이미 방문 -> pass
            if (parent[nxt] != -1) continue;

            // 처음방문: 부모로 설정
            parent[nxt] = cur;
            que.push(nxt);
        }
    }

    for (int j = 2; j <= n; j++) {
        cout << parent[j] << '\n';
    }

    return 0;
}