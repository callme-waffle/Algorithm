#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int t = (brown/2)+2;
    int w = t/2 + (t%2), h = t/2;
    
    while(w <= t && h >= 0) {
        if ((w-2)*(h-2) == yellow) break;
        w++; h--;
    }
    
    vector<int> res;
    res.push_back(w); res.push_back(h);
    return res;
}