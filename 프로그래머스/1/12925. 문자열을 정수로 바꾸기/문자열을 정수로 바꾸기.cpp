#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool is_minus = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') continue;
        if (s[i] == '-') {
            is_minus = true;
            continue;
        }
        answer *= 10;
        answer += (s[i] - '0');
    }
    return answer * (is_minus ? -1 : 1);
}