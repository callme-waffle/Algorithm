#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, c, nc = 0;
vector<int> nums;
unordered_map<int, int> cnt;

int bisect(int l, int r);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n; int t;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (cnt[t] == 0) nums[nc++] = t;
        cnt[t]++;
    }
    
    sort(nums.begin(), nums.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        cout << bisect(0, n) << '\n';
    }

    return 0;
}

int bisect(int l, int r) {
    if (r-l <= 1) return nums[l] == c ? cnt[c] : 0;
    
    int mid = (l+r)/2;
    if (nums[mid] <= c) return bisect(mid, r);
    return bisect(l, mid);
}