#include <iostream>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int size = max(n, k)*3;

    unordered_map<int, int> mm;
    queue<int> stb;

    // 초기화
    int c = n, cnt = 0;
    mm[c] = 0;
    stb.push(c);

    // 순회
    while(!stb.empty()) {
        c = stb.front(); stb.pop();

        if (c == k) {
            cout << mm[c] << '\n';
            return 0;
        }

        if (c <= size) {
            if (c+1 <= size && mm.find(c+1) == mm.end()) {
                stb.push(c+1);
                mm[c+1] = mm[c]+1;
            }
            if (c*2 <= size && mm.find(c*2) == mm.end()) {
                stb.push(c*2);
                mm[c*2] = mm[c]+1;
            }
        }
        if (c-1 >= 0 && mm.find(c-1) == mm.end()) {
            stb.push(c-1);
            mm[c-1] = mm[c]+1;
        }
    }

    cout << abs(k-n) << '\n';

    return 0;
}