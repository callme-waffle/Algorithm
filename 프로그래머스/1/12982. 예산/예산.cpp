#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int cursum = 0, cnt = 0;
    while(
        (cursum + d[cnt]) <= budget && 
        cnt < d.size()
    ) {
        cursum += d[cnt++];
    }
    
    return cnt;
}