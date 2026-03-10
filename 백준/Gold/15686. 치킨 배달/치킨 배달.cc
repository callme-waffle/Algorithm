#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
vector<int> selected;

int min_dists = 10000000;

void scan();
void selectChickens(int last_select);
void getChickenDist();

int main() {

    scan();
    selectChickens(-1);

    cout << min_dists << '\n';

    return 0;
}

void scan() {
    cin >> n >> m;
    int t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (t == 2) chickens.push_back({i, j});
            else if (t == 1) homes.push_back({i, j});
        }
    }
}

void selectChickens(int last_select) {
    if (selected.size() <= m) getChickenDist();
    
    for (int i = last_select+1; i < chickens.size(); i++) {
        // cout << "ADD_CHICKENS: " << i << endl;
        selected.push_back(i);
        selectChickens(i);
    
        // cout << "REMOVE_CHICKENS: " << i << endl;
        selected.pop_back();
    }
}

void getChickenDist() {
    vector<int> dists(homes.size(), 100);
    for (int i = 0; i < homes.size(); i++) {
        for (int chk: selected) {
            dists[i] = min(
                dists[i], 
                abs(chickens[chk].first-homes[i].first)
                 + 
                abs(chickens[chk].second-homes[i].second)
            );
        }
    }

    int total_dists = 0;
    for (auto dist: dists) total_dists += dist;

    // cout << "TOTAL_DIST: "<< total_dists << endl;
    min_dists = min(min_dists, total_dists);
}