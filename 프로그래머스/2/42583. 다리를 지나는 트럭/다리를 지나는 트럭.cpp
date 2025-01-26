#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int bridge_length, int weight, vector<int> truck_weights) {
    long long t = 1ll; // 다음 차가 들어오는 시간
    queue<int> ot;
    
    auto s = truck_weights.begin();
    auto e = s;
    auto fin = truck_weights.end();
    int w = 0, c = 0;
    while(s < fin) {
        cout << "t: " << t << endl;
        
        while(w <= weight && c < bridge_length && e < fin) {
            if((w + *e) > weight) break;
            cout << "in: " << *e << " at " << t << " (~" << (t + bridge_length) << ")" << endl;
            w += *e;
            e++;
            c++;
            ot.push((t++) + bridge_length);
        }
        
        cout << ot.size() << endl;

        cout << "update t: " << ot.front() << endl;
        t = ot.front() > t ? ot.front() : t;
        ot.pop();
        w -= *s;
        c--;
        s++;
    }
    
    return t;
}