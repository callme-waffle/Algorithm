#include <iostream>
#include <queue>

using namespace std;

int main() {

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    int i = 1;
    while(q.size() != 1) {
        if ((i++)%2 == 0) q.push(q.front());
        q.pop();
    }

    cout << q.front() << '\n';

    return 0;
}