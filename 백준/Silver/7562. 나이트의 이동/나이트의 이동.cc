#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};
vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int t;
    int bs; // 보드의 크기
    queue<pair<int, int>> stb; // 방문예정지
    vector<vector<int>> visited; // 해당위치로 이동하는 최소횟수

    cin >> t;

    for (int i = 0; i < t; i++) {
        stb = queue<pair<int, int>>();
        cin >> bs;

        visited = vector<vector<int>>(bs, vector<int>(bs, -1));
        
        int sx, sy, ex, ey;
        cin >> sy >> sx;
        cin >> ey >> ex;

        // 초기화
        stb.push({sy, sx}); visited[sy][sx] = 0;

        // 순회
        while(!stb.empty()) {
            pair<int, int> loc = stb.front(); stb.pop();
            int cy = loc.first, cx = loc.second;

            // 정답위치인 경우 이동거리를 return 
            // if (cy == ey && cx == ex) {
                
            // }

            for (int di = 0; di < 8; di++) {
                int ny = cy + dy[di], nx = cx + dx[di];
                if ( !(
                    ny >= 0 && nx >= 0 &&
                    ny < bs && nx <bs
                ) ) continue; // 범위초과 시 pass
                if (visited[ny][nx] > -1) continue; // 이미 방문한 경우 pass; bfs이므로 이후 방문하는 경우 항상 기존 도달방법보다 이동횟수가 큼

                // 이동횟수 기록
                visited[ny][nx] = visited[cy][cx]+1;

                // 방문예정지로 등록
                stb.push({ny, nx});
            }
        }

        if (visited[ey][ex] == -1) cout << "0\n";
        else cout << visited[ey][ex] << '\n';

    }
    return 0;
}