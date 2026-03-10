#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pc = 0, yc = 0;
    for (char c: s) {
        switch(tolower(c)) {
            case 'p':
                pc++;
                break;
            case 'y':
                yc++;
                break;
        }
    }
    return pc == yc;
}