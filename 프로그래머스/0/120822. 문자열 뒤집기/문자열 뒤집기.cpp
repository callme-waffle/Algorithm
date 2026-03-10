#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    auto iter = my_string.end()-1;
    for (int i = 0; i < my_string.size(); i++) {
        answer.push_back(*iter--);
    }
    return answer;
}