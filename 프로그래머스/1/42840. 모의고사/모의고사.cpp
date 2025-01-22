#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < answers.size(); i++) {
        if(patterns[0][i%patterns[0].size()] == answers[i]) a++;
        if(patterns[1][i%patterns[1].size()] == answers[i]) b++;
        if(patterns[2][i%patterns[2].size()] == answers[i]) c++;
    }
    
    int o_max = max(max(a, b), c);
    if (a == o_max) answer.push_back(1);
    if (b == o_max) answer.push_back(2);
    if (c == o_max) answer.push_back(3);
    
    return answer;
}