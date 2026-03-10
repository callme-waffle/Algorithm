#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    float rem = n;
    int div = 1;
    
    // 중단: 나눠진 수가 현재값보다 작거나 같아지면
    // 1. 현재값이 나눌 수 있다면 -> 카운트+1
    // 2. 현재값++, 나눠진 수 = n/현재값
    
    int cnt = 0;
    while(rem > div) {
        if (n % div == 0) cnt++;
        
        div++;
        rem = (float)n/div;
    }
    
    if (cnt == 1) return 2;
    
    cnt *= 2;
    if (rem == div) cnt++;
    
    return cnt;
}