#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    auto begin_range = num_list.begin();
    auto end_range = num_list.end();
    while(begin_range < end_range) {
        vector<int> row(begin_range, begin_range+n);
        answer.push_back(row);
        begin_range += n;
    }
    return answer;
}