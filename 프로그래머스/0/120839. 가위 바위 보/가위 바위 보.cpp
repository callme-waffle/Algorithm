#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string result = "";
    
    for (int i = 0; i < rsp.size(); i++) {
        char win;
        switch(rsp[i]) {
            case '2':
                win = '0';
                break;
            case '0':
                win = '5';
                break;
            case '5':
                win = '2';
                break;
        }
        result.push_back(win);
    }
    
    return result;
}