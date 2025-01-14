#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    int repeat = to_string(age).size();
    for (int i = 0; i < repeat; i++) {
        int digit = age % 10;
        answer.insert(0, {(char)(digit + 'a')});
        age /= 10;
    }
    return answer;
}