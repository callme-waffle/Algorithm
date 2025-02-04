#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, m, t, s = 0;
    cin >> n >> m;

    vector<int> a;
    vector<int> sum;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        
        s += t;
        sum.push_back(s);
    }

    int cnt = 0;
    for (int s = n-1; s >= 0; s--) {
        for (int e = s-1; e >= 0; e--) {
            int rs = sum[s] - sum[e];
            if (rs == m) cnt++;
        }
        int rs = sum[s];
        if (rs == m) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}