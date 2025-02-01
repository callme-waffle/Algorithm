#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    if (n == 1) return 4;
    
    long long r = 1, v = 2;
    while(r <= n) {
        r = (v*(v++));
        if (r == n) return v*v;
    }
    return -1;
}