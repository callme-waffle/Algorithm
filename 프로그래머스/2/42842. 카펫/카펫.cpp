#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int w = yellow, h = 1;
    while (w >= h) {
        if ((2*(w + h) + 4) == brown) break;
        bool changed = false;
        for (int div = h+1; div < w; div++) {
            if (yellow%div == 0) {
                changed = true;
                w = yellow/div;
                h = div;
                break;
            }
        }
        
        if (!changed) break;
    }
    
    return vector<int>({w+2, h+2});
}