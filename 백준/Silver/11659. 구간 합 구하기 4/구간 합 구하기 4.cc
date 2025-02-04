#include <iostream>
#include <vector>

using namespace std;

int main() {
    // fastio
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> sum(n+1);

    sum[0] = 0;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        sum[i+1] = sum[i] + t;
    }

    for (int j = 0; j < m; j++) {
        int s, e;
        cin >> s >> e;
        cout << (sum[e] - sum[s-1]) << '\n';
    }

    return 0;
}