#include <iostream>
#include <vector>

using namespace std;

int n, m;
int r, c, d;
vector<vector<int>> area;

int clean_cnt = 0;

vector<pair<int, int>> moves = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
vector<pair<int, int>> back_moves = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

void input();
void clean(int r, int c);

bool is_all_cleaned(int y, int x);
bool is_backable(int y, int x);
bool is_front_need_clean(int y, int x);
void go_front(int y, int x);
void go_back(int y, int x);

int main() {

    input();
    clean(r, c);

    cout << clean_cnt << '\n';

    return 0;
}

void input() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> r >> c >> d;
    if (d%2 == 1) d = (d+2)%4;

    area = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> area[i][j];
        }
    }
}

void clean(int y, int x) {
    // 1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
    if (area[y][x] == 0) {
        clean_cnt++;
        area[y][x] = 100;
    }

    // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
    if (is_all_cleaned(y, x)) {
        // 1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 
        if (is_backable(y, x)) {
            // 한 칸 후진하고 1번으로 돌아간다.
            return go_back(y, x);
        } 
        // 2. 아니라면 작동을 멈춘다.
        else return;
    }

    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
    else {
        // 1. 반시계 방향으로 90도 회전한다.
        d = (d+1)%4;

        // 2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        if (is_front_need_clean(y, x)) return go_front(y, x);
        
        // 3. 1번으로 돌아간다.
        return clean(y, x);
    }
}

bool is_all_cleaned(int y, int x) {
    bool all_cleaned = true;
    for (int i = 0; i < 4; i++) {
        int ny = y+moves[i].first;
        int nx = x+moves[i].second;

        if ( !(
            (0 <= ny && ny < n) &&
            (0 <= nx && nx < m)
        ) ) continue;

        if (area[ny][nx] == 0)
            all_cleaned = false;
    }

    return all_cleaned;
}
bool is_backable(int y, int x) {

    int ny = y+back_moves[d].first;
    int nx = x+back_moves[d].second;

    if ( !(
        (0 <= ny && ny < n) &&
        (0 <= nx && nx < m)
    ) ) return false;

    // 벽인 경우 후진 불가
    if (area[ny][nx] == 1) return false;
    
    return true;
}
bool is_front_need_clean(int y, int x) {

    int ny = y+moves[d].first;
    int nx = x+moves[d].second;

    if ( !(
        (0 <= ny && ny < n) &&
        (0 <= nx && nx < m)
    ) ) return false;

    return area[ny][nx] == 0;
}

void go_front(int y, int x) {

    int ny = y+moves[d].first;
    int nx = x+moves[d].second;

    if ( !(
        (0 <= ny && ny < n) &&
        (0 <= nx && nx < m)
    ) ) return;

    if (area[ny][nx] == 1) return;

    return clean(ny, nx);
}
void go_back(int y, int x) {

    int ny = y+back_moves[d].first;
    int nx = x+back_moves[d].second;

    if ( !(
        (0 <= ny && ny < n) &&
        (0 <= nx && nx < m)
    ) ) return;

    if (area[ny][nx] == 1) return;

    return clean(ny, nx);
}