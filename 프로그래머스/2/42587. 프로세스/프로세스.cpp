#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(int a, int b) { return a > b; }

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
        q.push(make_pair(priorities[i], i));
    
    sort(priorities.begin(), priorities.end(), comp);
    
    int run_cnt = 0;
    while(!q.empty()) {
        auto p = q.front(); q.pop();
        if (p.first != priorities[run_cnt]) {
            q.push(p);
            continue;
        }
        run_cnt++;
        if (p.second == location) return run_cnt;
    }
    return -1;
}