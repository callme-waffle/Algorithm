#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 0) {
            if (pq.size() == 0) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n'; 
                pq.pop();
            }
            continue;
        } 

        pq.push(t);
    }

    return 0;
}