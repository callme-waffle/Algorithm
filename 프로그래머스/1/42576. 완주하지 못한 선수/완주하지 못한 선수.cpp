#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> p;
    for (auto pn: participant) {
        if (p.find(pn) == p.end()) p[pn] = 0;
        p[pn]++;
    }
    for (auto pc: completion) {
        if (p[pc] == 1) p.erase(pc);
        else p[pc]--;
    }
    
    return p.begin()->first;
}