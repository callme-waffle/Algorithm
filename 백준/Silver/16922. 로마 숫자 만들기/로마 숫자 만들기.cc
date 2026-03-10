#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<int> answer; // 정답 set (toNum의 결과를 담음)

vector<int> vs = {1, 5, 10, 50}; // 로마숫자 
vector<int> nums; // 현재 선택된 로마숫자 index들
int sum = 0; // 선택된 로마숫자의 합

int n = 4, m;
void dupComb(); // 중복조합 연산

int main() {
    cin >> m;
    dupComb();
    cout << answer.size() << '\n';
    return 0;
}

void dupComb() {
    if (nums.size() == m) {
        answer.insert(sum);
        return;
    }

    int maxVal = (nums.size() == 0) ? 0 : nums.back();
    for (int i = maxVal; i < vs.size(); i++) {
        nums.push_back(i); sum += vs[i];
        dupComb();
        nums.pop_back(); sum -= vs[i];
    }
}