#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<vector<int>> pq; // vector끼리 정렬연산: 앞에있는 값부터 비교하여 정렬

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << -pq.top()[1] << '\n';
                pq.pop();
            }
        } else 
            pq.push({-abs(x), -x}); 
            // ㄴ 절댓값을 앞에 넣어 정렬에 참조하도록 하고, 절댓값이 같은 경우 위로 올라오도록 설계
            // ㄴ '-'는 큐를 최소힙으로 사용하기 위해 추가
    }

    return 0;
}
