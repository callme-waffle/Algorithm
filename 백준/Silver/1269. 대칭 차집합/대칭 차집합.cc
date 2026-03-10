#include <iostream>
#include <set>

using namespace std;

int main() {

    set<int> A, B;
    
    int n, m, t;
    
    cin >> n >> m;
    for (int j = 0; j < n; j++) {
        cin >> t;
        A.insert(t);
    }

    for (int j = 0; j < m; j++) {
        cin >> t;
        B.insert(t);
    }

    int cnt_a = A.size();
    for (int vb: B) {
        if (A.find(vb) != A.end()) cnt_a--;
    }

    int cnt_b = B.size();
    for (int va: A) {
        if (B.find(va) != B.end()) cnt_b--;
    }

    cout << (cnt_a + cnt_b) << '\n';

    return 0;
}