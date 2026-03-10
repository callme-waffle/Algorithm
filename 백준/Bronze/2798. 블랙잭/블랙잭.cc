#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> cards;
int m;
int answer;

void get_sum(int sum, int idx, int cnt) {
    if (cnt >= 3) {
        if (sum > m) return;
        answer = max(answer, sum);
        return;
    }

    int res = sum;
    for (int i = idx+1; i < cards.size(); i++) {
        get_sum(sum+cards[i], i, cnt+1);
    }

    return;
}

int main() {
    int n;
    cin >> n >> m;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        cards.push_back(tmp);
    }

    get_sum(0, 0, 0);
    cout << answer;
    return 0;
}