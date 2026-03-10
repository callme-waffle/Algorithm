#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        int sum = 0, point = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 'X') point = 0;
            else point++;

            sum += point;
        }

        cout << sum << '\n';
    }

    return 0;
}