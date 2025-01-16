#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    sort(array.begin(), array.end());
    
    int near = array[0];
    int diff = n-array[0];
    
    for (int& v: array) {
        int v_diff = v - n;
        if (v_diff < 0) v_diff *= -1;
        
        if (v_diff < diff) {
            near = v;
            diff = v_diff;
        }
    }
    
    return near;
}