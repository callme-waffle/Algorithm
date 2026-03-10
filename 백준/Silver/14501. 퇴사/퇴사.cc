#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> schedules;
vector<int> dp;

int getMaxProfit(int i);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    schedules.resize(n+1, {-1, -1});
    dp.resize(n+1, -1);
    
    for (int i = 1; i <= n; i++) {
        cin >> schedules[i].first >> schedules[i].second;
    }
    
    cout << getMaxProfit(1) << '\n';

    return 0;
}

int getMaxProfit(int i) {
    if (i > n) return 0;
    if (dp[i] > -1) return dp[i];
    
    // 1. 현재날짜에 시작하는 상담을 진행하지 않는 경우
    int profit = getMaxProfit(i+1);

    // 2. 현재날짜에 시작하는 상담을 진행하는 경우
    int endtime = schedules[i].first + i;
    int end_profit = schedules[i].second + getMaxProfit(endtime);

    // 최대 이익: 1과 2중 큰 경우
    if(endtime <= n+1) profit = max(profit, end_profit);
    dp[i] = profit;

    // cout << "PROFIT START FROM " << i << ": " << profit << endl;

    return dp[i];
}