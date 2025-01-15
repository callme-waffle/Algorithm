#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for (int v = 1; v <= n; v+=2) {
        answer.push_back(v);
    }
    return answer;
}