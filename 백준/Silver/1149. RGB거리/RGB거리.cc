#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> dp;
vector<vector<int>> cost;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp = vector<vector<int>>(n+1, vector<int>(3, 0));
    cost = vector<vector<int>>(n+1, vector<int>(3, -1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
        
        for (int j = 0; j < 3; j++) {
            dp[i][j] = min(
                dp[i-1][(j+1)%3] + cost[i][(j+1)%3],
                dp[i-1][(j+2)%3] + cost[i][(j+2)%3]
            );
        }
    }

    int min_cost = min(dp[n][0], dp[n][1]);
    min_cost = min(min_cost, dp[n][2]);

    cout << min_cost << '\n';

    return 0;
}