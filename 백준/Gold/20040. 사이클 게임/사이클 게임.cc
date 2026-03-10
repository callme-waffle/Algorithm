#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> parent;
vector<int> groupCnt;

int getParent(int a);
void merge(int x, int y);

int main() {

    cin >> n >> m;
    parent = vector<int>(n, -1);
    groupCnt = vector<int>(n, 1);

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;

        if (
            (getParent(x) == getParent(y)) &&
            (x != -1 && y != -1)
        ) {
            cout << i << '\n';
            return 0;
        }
    
        merge(x, y);
    }

    cout << "0\n";

    return 0;
}

int getParent(int a) {
    if (parent[a] == -1) return a;
    parent[a] = getParent(parent[a]);
    return parent[a];
}

void merge(int x, int y) {
    int px = getParent(x);
    int py = getParent(y);
    if (px == py) return;
    
    if (groupCnt[px] < groupCnt[py]) {
        parent[py] = px;
        groupCnt[px] += groupCnt[py];
    } else {
        parent[px] = py;
        groupCnt[py] += groupCnt[px];
    }
}
