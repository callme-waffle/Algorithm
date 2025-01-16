#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string before, string after) {
    map<char, int> count;
    for (auto& v: before) {
        count[v]++;
    }
    
    for (auto& v: after) {
        if (!count[v]) return 0;
        count[v]--;
    }
    
    return 1;
}