#include <iostream>
#include <vector>

#define MAX 123456789;

using namespace std;

vector<int> dp; // i를 1로 만들기 위해 사용하는 연산의 최소값

int getCount(int n);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;

    dp.resize(n+1, -1);

    // init
    dp[1] = 0; dp[2] = 1; dp[3] = 1;

    cout << getCount(n) << '\n';
    return 0;
}

int getCount(int n) {
    // dp: 앞에서 연산된 경우 연산없이 그대로 return
    if (dp[n] > -1) return dp[n];

    int poss1 = (n%3 == 0) ? (getCount(n/3) + 1) : MAX;
    int poss2 = (n%2 == 0) ? (getCount(n/2) + 1) : MAX;
    int poss3 = getCount(n-1) + 1;
    
    dp[n] = min(min(poss1, poss2), poss3);

    return dp[n];
}