#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int cv_cnt = 0, zc = 0;
    while(s != "1") {
        cv_cnt++;
        
        int oc = 0;
        for (int i = 0; i < s.size(); i++ ) {
            if (s[i] == '0') zc++;
            else oc++;
        }
        
        string ns = "";
        while(oc > 0) {
            ns += (oc%2) ? "1" : "0";
            oc/=2;
        }
        s = ns;
    }
    
    return vector<int>({ cv_cnt, zc });
}