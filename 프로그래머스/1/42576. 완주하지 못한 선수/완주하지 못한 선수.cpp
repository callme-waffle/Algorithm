#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> completions;
    for (string c: completion) completions[c]++;
    for (string p: participant) {
        if (completions[p] == 0) return p;
        completions[p]--;
    }
    return "";
}