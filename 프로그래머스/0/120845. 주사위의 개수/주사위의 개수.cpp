#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int total = 1;
    for (int v: box) {
        total *= v/n;
    }
    return total;
}