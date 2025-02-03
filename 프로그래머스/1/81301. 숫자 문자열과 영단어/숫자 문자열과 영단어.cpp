#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, pair<string, int>> a = {
        {"ze", {"0", 4}},
        {"on", {"1", 3}},
        {"tw", {"2", 3}},
        {"th", {"3", 5}},
        {"fo", {"4", 4}},
        {"fi", {"5", 4}},
        {"si", {"6", 3}},
        {"se", {"7", 5}},
        {"ei", {"8", 5}},
        {"ni", {"9", 4}}
    };
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        char v = s[i];
        if ('0' <= v && v <= '9') {
            ans += v;
            continue;
        }

        string key = s.substr(i, 2);
        i += (a[key].second-1);
        ans += a[key].first;
    }
    
    return stoi(ans);
}