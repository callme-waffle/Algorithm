#include <string>
#include <vector>

using namespace std;

vector<int> sp = {-1};
int solution(int n) {
    if (sp[0] == -1) {
        vector<int> a(n+1, -1);
        sp = a;
        sp[0] = 0;
        sp[1] = 1;
    }
    
    if (sp[n] > -1) return sp[n];
    
    int res = (solution(n-1) + solution(n-2)) % 1234567;
    sp[n] = res;
    
    return res;
}