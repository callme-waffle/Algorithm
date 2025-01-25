#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> ans;
    int last = -1;
    for (int a: arr) {
        if (a == last) continue;
        ans.push_back(a);
        last = a;
    }
    return ans;
}