#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool cmp(string a, string b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), cmp);
    
    unordered_set<string> pb;
    for (string p: phone_book) {
        for (int i = 1; i <= p.size(); i++) {
            string sp = p.substr(0, i);
            if (pb.find(sp) != pb.end()) return false;
        }
        pb.insert(p);
    }
    
    return pb.size() == phone_book.size();
}