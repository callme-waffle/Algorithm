#include <iostream>
#include <vector>
// #include <unordered_map>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<char, bool>> cs; // 입력되어 정렬된 문자들; {문자, 모음여부}
// unordered_map<int> sel_cnt;
vector<int> sel; // 현재 선택한 문자의 idx
int mo_cnt = 0; // 현재 선택한 문자들 중 모음의 개수

void dupComb();
bool isMoEum(char c);
bool cmp(pair<char, bool> a, pair<char, bool> b);

int main() {
    cin >> m >> n;
    cs.resize(n);
    for (int i = 0; i < n; i++) {
        cs[i] = {'a', true};
        cin >> cs[i].first;
        cs[i].second = isMoEum(cs[i].first);
    }
    sort(cs.begin(), cs.end(), cmp);

    dupComb();
    return 0;
}

void dupComb() {
    if (sel.size() == m) {
        // 암호조건 판단
        // cout << "check: " << mo_cnt << endl;
        if ( !(mo_cnt >= 1 && m-mo_cnt >= 2) ) return;
        

        for (int& idx: sel)
            cout << cs[idx].first;

        cout << '\n';
        return;
    }

    int maxVal = (sel.size() == 0) ? -1 : sel.back();
    for (int i = maxVal+1; i < n; i++) {
        sel.push_back(i);
        // sel_cnt[i]++;
        // cout << "add: " << cs[i].first << endl;
        if (cs[i].second) mo_cnt++;

        dupComb();

        sel.pop_back();
        // if (sel_cnt[i] == 1) sel_cnt.erase(i);
        // else sel_cnt[i]--;
        if (cs[i].second) mo_cnt--;
    }
}

bool isMoEum(char c) {
    if (
        c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u'
    ) return true;
    return false;
}

bool cmp(pair<char, bool> a, pair<char, bool> b) {
    return a.first < b.first;
}