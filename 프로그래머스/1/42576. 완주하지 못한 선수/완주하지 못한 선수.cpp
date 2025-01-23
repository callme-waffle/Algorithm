#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> completions;
    for (string c: completion) completions[c]++;
    for (string p: participant) {
        if (completions[p] == 0) return p;
        completions[p]--;
    }
    return "";
}