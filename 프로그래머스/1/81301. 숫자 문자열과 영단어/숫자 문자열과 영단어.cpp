#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int solution(string s) {
    for (int i = 0; i < 10; i++) {
        string number = numbers[i];
        while(s.find(number) != string::npos) { // number가 계속 발견되는 동안
            s.replace(s.find(number), number.size(), to_string(i));// 문자를 숫자로 대체
        }
    }

    return stoi(s);
}