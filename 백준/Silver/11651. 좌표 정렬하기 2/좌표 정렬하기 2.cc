#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n, x, y;
    cin >> n;

    vector<pair<int, int>> coord;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coord.push_back({x, y});
    }
    sort(coord.begin(), coord.end(), cmp);

    for (pair<int, int> &c: coord) {
        cout << c.first << " " << c.second << '\n';
    }
    return 0;
}