#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int cnt = 0;
    long long calc = num;
    
    for (; cnt <= 500; cnt++) {
        if (calc == 1) return cnt;
        if (!(calc%2)) calc/=2;
        else calc = (calc*3+1);
    }
    
    return cnt > 500 ? -1 : cnt;
}