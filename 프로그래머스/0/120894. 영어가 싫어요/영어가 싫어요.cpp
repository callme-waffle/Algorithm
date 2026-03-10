#include <string>
#include <vector>
#include <map>

using namespace std;

struct element {
    int size;
    string value;
};

long long solution(string numbers) {
    vector<string> v = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    map<string, element> table;
    int cnt = 0;
    for (string a: v) {
        int size = a.size();
        string key = a.substr(0, 2);
        
        element v = {size, to_string(cnt++)};
        table[key] = v;
    }
    
    int iter = 0;

    while(iter < numbers.size()) {
        element info = table[numbers.substr(iter, 2)];
        numbers.replace(iter, info.size, info.value);
        iter++;
    }
    
    return stoll(numbers);
}