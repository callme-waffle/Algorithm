#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int a = 0;
    int b = 0;
    
    auto iter = numbers.begin();
    auto end = numbers.end();
    while(iter != end) {
        if (a < *iter) {
            b = a;
            a = *iter;
        }
        else if (b < *iter) b = *iter;
        iter++;
    }
    
    return a * b;
}