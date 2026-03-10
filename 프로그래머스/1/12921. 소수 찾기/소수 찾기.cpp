#include <string>
#include <vector>

using namespace std;

vector<bool> filter(1000000, true);

int solution(int n) {
    filter[0] = false;
    filter[1] = false;
    filter[2] = true;
    filter[3] = true;
    for (int i = 2; i < n; i++) 
        for (int j = i*2; j <= n; j += i) {
            filter[j] = false;
        }
    
    int sum = 0;
    for (int k = 0; k <= n; k++) if (filter[k]) sum++;
    return sum;
}