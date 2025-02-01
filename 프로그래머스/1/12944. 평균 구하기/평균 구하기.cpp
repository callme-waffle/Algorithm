#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum = 0;
    for (auto iter = arr.begin(); iter < arr.end(); iter++) sum += (*iter);
    return (double)sum/arr.size();
}