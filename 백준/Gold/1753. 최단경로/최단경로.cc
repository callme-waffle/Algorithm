#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define F first
#define S second
#define INF 1234567890

typedef pair<int, int> pii;

int N, M;
vector<vector<pii>> adj;
int st;

vector<int> dist; // 갱신판단 대기열
priority_queue<pii, vector<pii>, greater<pii>> pq; // {dist, v}을 담는 우선순위 큐; dist를 기준으로 정렬되어야 하므로 사용

void init();

int main() {

    init();

    dist[st] = 0;
    pq.push({0, st}); // 시작위치부터 갱신판단을 위해 대기열에 추가

    while(!pq.empty()) { // 노드의 개수만큼 순회 => n번
        int minDist = pq.top().first; // 최소비용
        int minDistIdx = pq.top().second; // 최소비용으로 갈 수 있는 노드의 index
        pq.pop();

        // 이번에 판단할 비용보다 기존에 이동하는 비용이 이미 더 좋다면 pass
        if (dist[minDistIdx] < minDist) continue;

        // 갈 수 있는 노드로 이동 후, 이동한 노드와 연결된 노드로 가는 비용 갱신
        for (int i = 0; i < adj[minDistIdx].size(); i++) {
            int next = adj[minDistIdx][i].first; // 연결된 노드의 index
            int edgeCost = adj[minDistIdx][i].second; // 현위치->연결된 노드 간 이동비용

            // 기존 계산결과보다 현재 계산결과가 더 좋은 경우
            if(dist[next] > minDist + edgeCost) {
                dist[next] = minDist + edgeCost; // 결과값 갱신
                pq.push({dist[next], next}); // 갱신된 이동비용과 노드의 index를 갱신판단 대기열에 추가
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int d = dist[i];
        if (d == INF) cout << "INF\n";
        else cout << d << '\n';
    }

    return 0;
}

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> st;
    adj.resize(N+1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // 간선의 정보; 
    }

    dist = vector<int>(N+1, INF);
}