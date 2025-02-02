#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int sn = 1, cnt = 0;
    while(sn <= n) {
        int sum = 0;
        for (int an = sn; sum <= n; an++) {
            sum += an;
            if (sum == n) {
                cnt++;
                break;
            }
        }
        sn++;
    }
    
    return cnt;
}