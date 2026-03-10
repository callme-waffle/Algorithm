#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n; cin >> n;
    vector<long long> nums(n);
    for (long long i = 0; i < n; i++) cin >> nums[i];

    sort(nums.begin(), nums.end());
    
    long long m, t; cin >> m;
    for (long long i = 0; i < m; i++) {
        cin >> t;
        
        long long sp = 0, ep = n;
        bool printed = false;

        while(sp <= ep && sp >= 0 && ep <= n) {
            int cp = (sp+ep)/2;
            if (nums[cp] == t) {
                cout << "1\n";
                printed = true; break;
            }

            if (sp == ep) break;

            if (nums[cp] < t) {
                sp = cp+1;
            } else {
                ep = cp-1;
            }
        }

        if (!printed) cout << "0\n";
    }

    return 0;
}