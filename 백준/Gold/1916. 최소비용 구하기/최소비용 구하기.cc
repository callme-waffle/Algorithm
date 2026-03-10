#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second
#define INF 1234567890

typedef pair<int, int> pii;

vector<vector<pii>> adj;
vector<int> dist;
vector<bool> check; // 정점의 경로가 최소임이 확인된 노드를 true로 기록
int N, M;
int st, en;

void init();
int findMinDist(); // 현재 dist 중 가장 작은 정점번호를 select; 모든 정점이 확싫시 된 경우 return -1

int main() {
    init();

    cin >> st >> en;

    dist[st] = 0;
    while(1) {
        int minDistIdx = findMinDist();
        if (minDistIdx == -1) break;

        check[minDistIdx] = true;

        // minDistIdx로 dist 갱신
        for (int i = 0; i < adj[minDistIdx].size(); i++) {
            int next = adj[minDistIdx][i].F;
            int cost = adj[minDistIdx][i].S;

            if (dist[next] > dist[minDistIdx] + cost) {
                dist[next] = dist[minDistIdx] + cost;
            }
        }
    }

    cout << dist[en];

    return 0;
}

int findMinDist() {
    int answer = -1;
    int minDist = INF;

    for (int i = 1;i <= N; i++ ) {
        if(check[i] == false && minDist > dist[i]) {
            minDist = dist[i];
            answer = i;
        }
    }

    return answer;
}

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    adj.resize(N+1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // 간선의 정보; 
    }

    dist = vector<int>(N+1, INF);
    check = vector<bool>(N+1, false);
}