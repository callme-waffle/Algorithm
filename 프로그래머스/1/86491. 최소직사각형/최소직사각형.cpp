#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int mw = 0, mh = 0;
    for (vector<int> card: sizes) {
        int w = card[0], h = card[1];
        if (w < h) {h = card[0]; w = card[1];}
        
        if (mw < w) mw = w;
        if (mh < h) mh = h;
    }
    
    return mw * mh;
}