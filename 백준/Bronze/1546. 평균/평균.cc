#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    
    int m = 0, n, t;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
        
        if (m < t) m = t;
    }

    double sum = 0;
    for (int& a: v) 
        sum += ((double(a)/m)*100);

    cout << sum/n << endl;

    return 0;
}