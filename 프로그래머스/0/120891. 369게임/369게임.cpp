#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int cnt = 0;
    while(order > 0) {
        int digit = order % 10;
        if (digit > 0 && (digit % 3 == 0)) cnt++;
        order /= 10;
    }
    return cnt;
}