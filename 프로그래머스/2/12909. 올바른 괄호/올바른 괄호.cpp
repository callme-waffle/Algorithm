#include<string>
#include <iostream>

using namespace std;

bool solution(string s) {
    int cnt = 0;
    for (char a: s) {
        switch(a) {
            case '(':
                cnt++;
                break;
            case ')':
                cnt--;
                if (cnt < 0) return false;
                break;
        }
    }
    return cnt == 0;
}