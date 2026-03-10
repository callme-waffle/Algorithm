#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int sum = 0;
    
    int iter = 0;
    int end = my_string.size();
    
    while(iter < end) {
        int count = 0;
        while(my_string[iter+count] >= '0' && my_string[iter+count] <= '9') {
            count++;
        }
        if (!count) {
            iter++;
            continue;
        }
        int v = stoi(my_string.substr(iter, count));
        sum += v;
        iter += count;
    }

    return sum;
}