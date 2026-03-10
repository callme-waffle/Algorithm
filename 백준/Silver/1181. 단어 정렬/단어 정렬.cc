#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> strs;

bool cmp(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main() {

    int n; cin >> n;
    strs.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    sort(strs.begin(), strs.end(), cmp);

    string prev = "";
    for (string str: strs) {
        if (prev != str) cout << str << '\n';
        prev = str;
    }

    return 0;
}