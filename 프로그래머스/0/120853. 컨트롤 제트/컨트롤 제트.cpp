#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int sum = 0, cache = 0;
    
    auto iter = 0;
    auto end = s.size();
    do {
        int loc = s.find(' ', iter);
        if (loc == string::npos) loc = end;
        
        string v = s.substr(iter, loc-iter);
        if (v == "Z") {
            sum -= cache;
            iter = loc+1;
            continue;
        }
        
        sum += stoi(v);
        cache = stoi(v);
        iter = loc+1;
    } while(iter < end);
    
    return sum;
}