#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    cout << nums[n-k] << '\n';

    return 0;
}