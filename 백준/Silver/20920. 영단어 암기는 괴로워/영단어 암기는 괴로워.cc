#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> wc;

bool cmp(string a, string b) {
    if (wc[a] != wc[b]) return wc[a] > wc[b];
    if (a.size() != b.size()) return a.size() > b.size();
    return a < b;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> note;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp.size() < m) continue;
        if (wc.find(tmp) != wc.end()) {
            wc[tmp]++;
            continue;
        }
        note.push_back(tmp);
        wc[tmp] = 1;
    }

    sort(note.begin(), note.end(), cmp);

    for (string &word: note) {
        cout << word << '\n';
    }

    return 0;
}