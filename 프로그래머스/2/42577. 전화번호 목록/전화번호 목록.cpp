#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> pns;
    sort(phone_book.begin(), phone_book.end());
    for (string pn: phone_book) {
        for (int i = 1; i <= pn.size(); i++) {
            if (pns.find(pn.substr(0, i)) != pns.end()) return false;
        }
        pns.insert(pn);
    }
    
    return true;
}