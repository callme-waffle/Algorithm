#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0;
    if (n <= 3) return 0;
    for (int i = 4; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (i%j == 0) {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}