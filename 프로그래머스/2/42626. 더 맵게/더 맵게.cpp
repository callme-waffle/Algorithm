#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long solution(vector<int> scoville, int K) {
    priority_queue<long long, vector<long long>, greater<long long>> scov(scoville.begin(), scoville.end());
    if (scov.top() >= K) return 0;
    
    long long cnt = 0ll;
    while(scov.size() >= 2) {
        long long a = scov.top(); scov.pop();
        long long b = scov.top(); scov.pop();
        long long new_scov = a + b*2;
        
        long long min_scov = scov.top();
        if (min_scov > new_scov) min_scov = new_scov;
        cnt++;
        
        if (min_scov >= K) return cnt;
        scov.push(new_scov);
    }
    
    if (scov.top() >= K) return cnt;
    
    return -1ll;
}