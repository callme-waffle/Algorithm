#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> sorted(emergency.begin(), emergency.end());
    vector<int> ans;
    sort(sorted.begin(), sorted.end());
    
    int size = sorted.size();
    int idx = 0;
    for (int i = 0; i < size; i++) {
        while(emergency[i] != sorted[idx]) {
            if (emergency[i] > sorted[idx]) idx++;
            else idx--;
        }
        ans.push_back(size-idx);
    }
    return ans;
}