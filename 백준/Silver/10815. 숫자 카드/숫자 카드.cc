#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c;
vector<int> nums;

int bisect(int l, int r);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c;
        cout << bisect(0, n) << '\n';
    }

    return 0;
}

int bisect(int l, int r) {
    if (r-l <= 1) return nums[l] == c ? 1 : 0;
    
    int mid = (l+r)/2;
    if (nums[mid] <= c) return bisect(mid, r);
    return bisect(l, mid);
}