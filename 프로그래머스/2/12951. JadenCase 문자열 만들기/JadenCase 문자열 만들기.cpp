#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (flag) {
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] -= ('a' - 'A');
            
            flag = false;
        } else if (!flag && 'A' <= s[i] && s[i] <= 'Z') {
            s[i] += ('a' - 'A');
        }
        if (s[i] == ' ') flag = true;
    }
    
    return s;
}