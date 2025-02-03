#include <iostream>

using namespace std;

int main() {
    string seq;
    cin >> seq;

    int res = 0, sum = 0, idx = 0;
    bool flag = false;

    int i = 0;
    do {
        char v = seq[i];
        if (v != '+' && v != '-' && i != seq.size()-1) {
            i++; continue;
        }

        int num = stoi(seq.substr(idx, (i-idx+(i == seq.size()-1)))); idx = i+1;
        sum += num;

        if (v == '-') {
            if (flag) {
                res -= sum;
            } else { // 첫 등장
                flag = true;
                res = sum;
            }
            sum = 0;
        }

        if (i == seq.size()-1) {
            if (flag) res -=sum;
            else res = sum;
        }

        i++;
    } while(i < seq.size());

    cout << res << endl;

    return 0;
}