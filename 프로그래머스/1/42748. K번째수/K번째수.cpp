#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command: commands) {
        vector<int> prob(array.begin()+command[0]-1, array.begin()+command[1]);
        sort(prob.begin(), prob.end());
        answer.push_back(prob[command[2]-1]);
    }
    return answer;
}