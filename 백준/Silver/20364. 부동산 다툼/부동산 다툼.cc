#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q, place;
    cin >> n >> q;
    unordered_map<int, int> home;
    for (int i = 0; i < q; i++) {
        cin >> place;

        int top_rich = -1;
        for (int parent = place; parent > 0; parent /= 2) {
            if (home.find(parent) != home.end()) top_rich = parent;
        }

        home[place] = place;

        if (top_rich == -1) cout << "0\n";        
        else cout << top_rich << '\n';
    }

    return 0;
}