#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return (a+a+a+a).substr(0, 4) < (b+b+b+b).substr(0, 4);
}

string solution(vector<int> numbers) {
    vector<string> str;
    for (int num: numbers) str.push_back(to_string(num));
    sort(str.begin(), str.end(), cmp);
    // for (string s: str) cout << s << " ";
    // cout << endl;
    
    string ans = "";
    bool all_zero = true;
    for (string s: str) {
        if (s.size() != 1 || s[0] != '0') all_zero = false;
        ans.insert(0, s);
    }
    if (all_zero) return "0";
    return ans;
}