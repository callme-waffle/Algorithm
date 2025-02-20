#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long n;
vector<vector<long long>> dp;

vector<long long> getECN(long long v);

int main() {

    cin >> n;
    dp = vector<vector<long long>>(max(4LL, n+1), vector<long long>(2, -1));

    // init
    dp[0][0] = 0; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 0; dp[2][1] = 1;
    dp[3][0] = 1; dp[3][1] = 1;

    // 계산
    vector<long long> cnts = getECN(n);
    cout << (cnts[0] + cnts[1]) << '\n';

    return 0;
}

vector<long long> getECN(long long v) {
    // dp: 기존 기록값 활용
    if (dp[v][0] > -1) return dp[v];

    // 재귀호출: 과거값 조회
    vector<long long> prev_v = getECN(v-1);

    // 이번에 '0'이 올 수 있는 경우: 앞전에 어떤수가 왔던 무관 -> 이전 모든 경우에 '0'을 붙인 숫자들을 카운트
    dp[v][0] = prev_v[0] + prev_v[1];
    // 이번에 '1'이 올 수 있는 경우: 앞전에 '0'이었던 경우에만 가능 -> '0'이었던 수에 '1'을 붙인 숫자들을 카운트
    dp[v][1] = prev_v[0];

    return vector<long long>({dp[v][0], dp[v][1]});
}