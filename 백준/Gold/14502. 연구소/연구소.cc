#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> loc;
vector<pair<int, int>> virus;

int max_safesize = 0;

void scan();
void addWall(int installed);
void checkSafeSize();

int main() {
    scan();
    addWall(0);

    cout << max_safesize << '\n';

    return 0;
}

void scan() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    loc = vector<vector<int>>(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> loc[i][j];
            if (loc[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
}

void addWall(int installed) {

    if (installed == 3) 
        return checkSafeSize();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (loc[i][j] != 0) continue;
            
            loc[i][j] = 1;
            addWall(installed+1);

            loc[i][j] = 0;
        }
}

void checkSafeSize() {
    vector<vector<int>> check(loc.begin(), loc.end());
    queue<pair<int, int>> stb;
    
    // init
    for (pair<int, int> v: virus) stb.push(v);

    while(!stb.empty()) {
        pair<int, int> v = stb.front(); stb.pop();
        int y = v.first, x = v.second;

        if (check[y][x] == 1) continue;
        check[y][x] = 2;
        
        if (y+1 < n && check[y+1][x] == 0) stb.push({y+1, x});
        if (y-1 >= 0 && check[y-1][x] == 0) stb.push({y-1, x});

        if (x+1 < m && check[y][x+1] == 0) stb.push({y, x+1});
        if (x-1 >= 0 && check[y][x-1] == 0) stb.push({y, x-1});
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if(check[i][j] == 0) cnt++;
    }

    max_safesize = max(max_safesize, cnt);
}