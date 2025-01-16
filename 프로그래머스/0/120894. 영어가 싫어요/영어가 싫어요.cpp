#include <string>
#include <vector>
#include <map>

using namespace std;

struct element {
    int size;
    int value;
};

long long solution(string numbers) {
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    map<string, element> table;
    int cnt = 0;
    for (string a: v) {
        int size = a.size();
        string key = a.substr(0, 2);
        
        element v = {size, cnt++};
        table[key] = v;
    }
    
    int iter = 0;
    int end = numbers.size();
    
    string answer = "";
    
    while(iter < end) {
        element info = table[numbers.substr(iter, 2)];
        iter += info.size;
        answer.replace(answer.size(), 0, to_string(info.value));
    }
    
    return stoll(answer);
}