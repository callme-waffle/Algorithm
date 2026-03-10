#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long a = x;
    do {
        answer.push_back(a);
        a+=x;
    } while (answer.size() < n);
    return answer;
}