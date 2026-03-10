#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> divs;
        
    int div = 2;
    while(n >= div) {
        if (n%div > 0) {
            div++;
            continue;
        }
        
        while (n%div == 0) {
            n /= div;
        }
        divs.push_back(div);
        div++;
    }
    
    return divs;
}