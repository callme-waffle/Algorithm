#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    int sum = 0, large = -10000000;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        
        sum += c[i];
        if (i >= m) sum -= c[i-m];

        if (i >= m-1) large = max(large, sum);
    }

    cout << large << '\n';

    return 0;
}