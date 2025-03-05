#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    map<string, float> weight = {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0}
    };

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    float sum = 0, psum = 0;
    int passcnt = 0;

    for (int i = 0; i < 20; i++) {
        string _, weight_str; float point;
        cin >> _ >> point >> weight_str;

        if (weight_str == "P") {
            passcnt++;
            continue;
        }

        psum += point;
        sum += (point * weight[weight_str]);
    }

    cout << sum / psum << '\n';
    
    return 0;
}