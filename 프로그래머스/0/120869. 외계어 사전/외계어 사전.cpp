#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for (string word: dic) {
        int pass_count = 0;
        for (string a: spell) {
            // 아예 없는경우 확인
            int idx = word.find(a, 0);
            if (idx == string::npos) break;

            // 2개 이상인 경우 확인
            idx = word.find(a, idx+1);
            if (idx != string::npos) break;
            
            pass_count++;
        }
        
        // 조건에 일치하는 단어를 찾은 경우
        if (pass_count == spell.size()) return 1;
    }
    
    return 2;
}