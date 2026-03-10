#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    int sum = 0, ci = 0, t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (!t) {
            sum -= s.top();
            s.pop();
        } else {
            s.push(t);
            sum += t;
        }
    }

    cout << sum << '\n';
    return 0;
}