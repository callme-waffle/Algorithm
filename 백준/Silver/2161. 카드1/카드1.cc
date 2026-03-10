#include <iostream>
#include <queue>

using namespace std;

int main() {
    int v; cin >> v;

    queue<int> q;
    for (int i = 1; i <= v; i++) {
        q.push(i);
    }

    while(q.size() > 1) {
        cout << q.front() << ' '; q.pop();
        if (q.size() <= 1) break;
        
        q.push(q.front()); q.pop();
    }

    cout << q.front(); q.pop();
    return 0;
}