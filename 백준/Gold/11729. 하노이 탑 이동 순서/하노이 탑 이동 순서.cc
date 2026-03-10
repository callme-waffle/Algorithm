#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> logs;

void hanoi(int n, int from, int to, int empty);

int main() {
    int n;
    cin >> n;
    
    hanoi(n, 1, 3, 2);

    cout << logs.size() <<  '\n';
    for (pair<int, int> log: logs) {
        cout << log.first << ' ' << log.second << '\n';
    }
    return 0;
}

void hanoi(int n, int from, int to, int empty) {// 옮기려고 하는 가장 큰 원판,
    if (n > 1) hanoi(n-1, from, empty, to);
    logs.push_back({from, to});
    if (n > 1) hanoi(n-1, empty, to, from);
}