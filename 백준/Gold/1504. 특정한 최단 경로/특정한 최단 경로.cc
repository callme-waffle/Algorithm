#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 123456789
typedef pair<int, int> pii;

int n, e; // 노드 수, 간선 수
vector<vector<pii>> adj; // 인접리스트
priority_queue<pii, vector<pii>, greater<pii>> pq; // 이동판단 대기열
int u, v; // 필수방문 점1, 점2

int dijkstra(int from, int to);
void scan();

int main() {
    scan();

    int s_to_u = dijkstra(1, u);
    int s_to_v = dijkstra(1, v);
    int u_to_v = dijkstra(u, v);
    int u_to_d = dijkstra(u, n);
    int v_to_d = dijkstra(v, n);

    bool a_unavail = false, b_unavail = false;

    if (s_to_u == INF || u_to_v == INF || v_to_d == INF) a_unavail = true;
    if (s_to_v == INF || u_to_v == INF || u_to_d == INF) b_unavail = true;

    if ( a_unavail && b_unavail ) {
        cout << "-1\n";
        return 0;
    }

    int case_a = s_to_u + u_to_v + v_to_d;
    int case_b = s_to_v + u_to_v + u_to_d;
    
    cout << min(case_a, case_b) << '\n';
    return 0;
}

int dijkstra(int from, int to) {
    vector<int> dist(n+1, INF); // 이떄까지 연산된 i번째 노드까지의 최소비용

    // 초기화
    pq.push({0, from});
    dist[from] = 0;

    int curr = from;
    while(!pq.empty()) {
        int poss_to = pq.top().second, poss_cost = pq.top().first;
        pq.pop();

        if (dist[poss_to] < poss_cost) continue;
        
        // dist[poss_to] = dist[curr] + poss_cost;
        curr = poss_to;

        for (pii& adj_info: adj[curr]) {
            int movable_node = adj_info.second, movable_cost = adj_info.first;
            if (dist[movable_node] > dist[curr] + movable_cost) {
                dist[movable_node] = dist[curr] + movable_cost;
                pq.push({dist[movable_node], movable_node});
            }
        }
    }

    return dist[to];
}

void scan() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> e;
    adj.resize(n+1);

    int from, to, cost;
    
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> cost;
        adj[from].push_back({cost, to});
        adj[to].push_back({cost, from});
    }

    cin >> u >> v;
}