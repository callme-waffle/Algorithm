#include <iostream>

using namespace std;

int main() {

    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;

        if (v <= 1) continue;

        bool is_prime = true;
        for (int j = 2; j < v; j++) {
            if (v%j == 0) {
                is_prime = false;
                break;
            }
        }
        
        if (is_prime) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}