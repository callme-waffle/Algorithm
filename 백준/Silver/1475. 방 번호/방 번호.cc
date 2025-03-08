#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> counts(10, 0);
    while(n > 0) {
        int d = n%10;
        if (d == 9) d = 6;

        counts[d]++;
        n /= 10;
    }

    int mv = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) {
            mv = max(mv, (counts[i]+1)/2);
        }
        else mv = max(mv, counts[i]);
    }

    cout << mv << '\n';

    return 0;
}