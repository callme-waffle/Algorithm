#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int t = 1ll;
    queue<int> ot;
    
    auto s = truck_weights.begin();
    auto e = s;
    auto fin = truck_weights.end();
    
    int w = 0, c = 0;
    while(s < fin) {
        // 무게한도 or 길이한도 초과 전까지 계산
        while((w + *e) <= weight && c < bridge_length && e < fin) {
            w += *e;
            e++;
            c++;
            ot.push((t++) + bridge_length);
        }
        t = ot.front() > t ? ot.front() : t;
        ot.pop();
        w -= *s;
        c--;
        s++;
    }
    
    return t;
}