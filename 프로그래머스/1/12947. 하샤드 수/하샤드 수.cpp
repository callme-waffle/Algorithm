#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, div = x;
    while(div > 0) {
        sum += (div%10);
        div /= 10;
    }
    return x%sum == 0;
}