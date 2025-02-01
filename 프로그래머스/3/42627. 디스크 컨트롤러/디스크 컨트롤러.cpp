#include <string>
#include <vector>
#include <queue>
#include <algorithm>

// #include <iostream>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        if (a[0] != b[0]) return a[0] > b[0];
        if (a[1] != b[1]) return a[1] > b[1];
        return a[2] > b[2];
    }
};

bool job_sort(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    priority_queue<int, vector<int>, greater<int>> time;
    priority_queue<vector<int>, vector<vector<int>>, cmp> stq;
    
    sort(jobs.begin(), jobs.end(), job_sort);
    for (int i = 0; i < jobs.size(); i++) time.push(jobs[i][0]);
    
    auto job = jobs.begin();
    
    int res = 0; int id = 0;
    int prt = -1, pet = -1;
    int curr = 0;
    
    // 가장 빠른 시작시간으로 이동하여 시작 (0초작업 없는경우 고려)
    time.push((*job)[0]);
    stq.push(vector<int>({(*job)[1], (*job)[0], id++})); // 소요시간, 요청시간, ID
    // cout << "[PREADD]" << "== | Process ADD: " << id-1 << "| need: " << (*job)[1] << " | ==" << endl;
    job++;
    
    while(!time.empty()) {
        curr = time.top(); time.pop();
        // cout << "[TIME_" << curr << "]" << endl;
        
        if (pet == curr) { // 프로세스가 종료되는 경우
            // cout << "[TIME_" << curr << "]" << "== | Process END: " << prt << "~" << pet << " | ==" << endl;
            res += (pet - prt);
            pet = -1; prt = -1;
        }
        
        while(job < jobs.end() && (*job)[0] ==curr) { // 추가할 값이 있는경우 queue에 추가
            // cout << "[TIME_" << curr << "]" << "== | Process ADD: " << id << "| need: " << (*job)[1] << " | ==" << endl;
            stq.push(vector<int>({(*job)[1], (*job)[0], id++})); // 소요시간, 요청시간, ID
            job++;
        }
        
        if (time.empty() && stq.empty()) break; // 검토할 시간도 없고, 실행스택도 비어있다면 중단
        if (stq.empty()) continue; // 검토할 시간은 있는데 실행스택만 비어있다면 다음 검토시간으로 이동
        
        if (pet > -1) continue; // 실행중인 프로세스가 있는 경우 더이상 진행하지 않음

        // cout << "[TIME_" << curr << "]" << "== | Process Start: " << stq.top()[2] << " | requested: " << stq.top()[1] << " | duration: " << stq.top()[0] << " | ==" << endl;
        
        prt = stq.top()[1]; pet = curr + stq.top()[0]; stq.pop();
        time.push(pet);
        
        
    }
    
    return res/(jobs.size());
}