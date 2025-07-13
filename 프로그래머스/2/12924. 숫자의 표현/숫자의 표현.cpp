#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int s = 1, e = 1;
    int cursum = 1;
    int cnt = 0;
    while(s <= n && e <= n) {
        if (cursum < n) cursum += (++e);
        else if (cursum > n) cursum -= (s++);
        
        if (cursum == n) {
            cout << s << " " << e << endl;
            cnt++; 
            e++; cursum += e;
            continue;
        }
    }
    
    return cnt;
}