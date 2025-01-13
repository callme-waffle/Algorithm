#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int sum = 0;
    int max = 0;
    
    for (int i = 0; i < sides.size(); i++) {
        if (max < sides[i]) {
            sum += max;
            max = sides[i];
        }
        else sum += sides[i];
    }
    
    return sum > max ? 1 : 2;
}