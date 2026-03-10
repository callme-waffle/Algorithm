#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

    string str; cin >> str;
    stack<char> s;
    stack<pair<long long, int>> s_sum;

    long long res = 0; int level = 0;
    for (char c: str) {
        if (c == '(' || c == '[') {
            s.push(c);
            level++;
        } else {
            if (s.empty()) {
                cout << "0\n";
                return 0;
            }

            char p = s.top(); s.pop();

            int v;
            if (p == '(' && c == ')') v = 2;
            else if (p == '[' && c == ']') v = 3;
            else {
                cout << "0\n";
                return 0;
            }

            pair<long long, int> tv;
            if (!s_sum.empty()) {
                do {
                    tv = s_sum.top(); s_sum.pop();
                    if (tv.second > level) {
                        v *= tv.first;
                    }
                    else if (tv.second == level) {
                        v += tv.first;
                    } else {
                        s_sum.push(tv);
                    }
                } while(tv.second >= level && !s_sum.empty());
            }

            s_sum.push({v, level});
            level--;
        }
    }

    if (!s.empty()) {
        cout << "0\n";
        return 0;
    }

    while(!s_sum.empty()) {
        res += s_sum.top().first; s_sum.pop();
    }

    cout << res << '\n';

    return 0;
}