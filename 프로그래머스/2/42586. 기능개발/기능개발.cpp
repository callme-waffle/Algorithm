#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    stack<int> works;
    for (int i = speeds.size()-1; i >= 0; i--) {
        int rem = 100 - progresses[i];
        works.push((rem/speeds[i]) + (rem%speeds[i] ? 1 : 0));
    }
    
    vector<int> answer;
    while(!works.empty()) {
        int day = works.top(), cnt = 1;
        works.pop();
        while(!works.empty() && works.top() <= day) {
            cnt++;
            works.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}