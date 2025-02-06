#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;

int bisectQ1(int l, int r);
int bisectQ2(int l, int r);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    num.resize(N);
    for (int i = 0; i < N; i++) cin >> num[i];
    sort(num.begin(), num.end());

    int cnM;
    cin >> cnM;
    for (int i = 0; i < cnM; i++) {
        cin >> M;
        int se_idx = bisectQ1(-1, N); // 작거나 같은지
        int s_idx = bisectQ2(-1, N); // 작은지
        cout << se_idx - s_idx << ' ';
    }

    return 0;
}

int bisectQ1(int l, int r) {
    // 중단조건
    if (r-l <= 1) return l; // l/r 결정조건 확인필요
    
    int mid = (l+r)/2;
    if (num[mid] <= M) return bisectQ1(mid, r);
    return bisectQ1(l, mid);
}

int bisectQ2(int l, int r) {
    // 중단조건
    if (r-l <= 1) return l; // l/r 결정조건 확인필요
    
    int mid = (l+r)/2;
    if (num[mid] < M) return bisectQ2(mid, r);
    return bisectQ2(l, mid);
}