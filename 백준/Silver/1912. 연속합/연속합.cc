#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t, maxsum = -1000000, cursum = -100000;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        cursum += t;

        if (cursum < t) cursum = t;    
        if (cursum > maxsum) maxsum = cursum;
    }

    cout << maxsum << '\n';

    return 0;
}