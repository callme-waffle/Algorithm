#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int solution(vector<vector<string>> clothes) {
    set<string> keys;
    unordered_map<string, vector<string>> cs;
    for (vector<string> c: clothes) {
        if (keys.find(c[1]) == keys.end()) {
            vector<string> cl = {c[0]};
            keys.insert(c[1]);
        }
        cs[c[1]].push_back(c[0]);
    }
    
    int mul = 1;
    for (string key: keys) {
        mul *= cs[key].size()+1;
    }
    return mul-1;
}