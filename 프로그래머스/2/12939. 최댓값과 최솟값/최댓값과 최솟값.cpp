#include <iostream>
#include <string>
#include <vector>

using namespace std;

int updateMaxMin(string subs, int& maxv, int& minv);

string solution(string s) {
    int prev = 0;
    int sp = s.find(" ");
    int maxv = 0, minv = 0, cnt = 0;
    int v;
    
    for(int cnt = 0; sp != -1; cnt++) {        
        v = updateMaxMin(s.substr(prev, sp-prev), maxv, minv);
        if (cnt == 0) {
            maxv = v;
            minv = v;
        }
        
        prev = sp+1; sp = s.find(" ", sp+1);
    }
    
    updateMaxMin(s.substr(prev, sp-prev), maxv, minv);
    
    return to_string(minv) + " " + to_string(maxv);
}

int updateMaxMin(string subs, int& maxv, int& minv) {
    int v = stoi(subs);
    
    if (maxv < v) maxv = v;
    if (minv > v) minv = v;
    
    return v;
}