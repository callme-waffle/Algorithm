#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int res = 1, mul = 1;
    while(n >= res) {
        res *= ++mul;
    }
    return mul-1;
}