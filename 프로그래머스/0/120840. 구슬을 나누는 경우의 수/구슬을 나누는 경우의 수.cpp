#include <string>
#include <vector>

using namespace std;

long long comb(int a, int b) {
    if (b == 0 || a <= 1) return 1;
    if (a/2 < b) return comb(a, a - b);
    
    long long sum = 0l;
    for (int i = a-1; i >= b-1; i--) {
        sum += comb(i, b-1);
    }
    return sum;
}

long long solution(int balls, int share) {
    return comb(balls, share);
}