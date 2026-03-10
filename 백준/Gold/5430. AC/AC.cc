#include <iostream>
#include <vector>
#include <string>

int T, p;

using namespace std;

vector<int> parseNums(string strs);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> nums;

    cin >> T;
    for (int i = 0; i < T; i++) {
        string cmd; cin >> cmd;

        int v; cin >> v;
        nums.resize(v);

        string nums_str; cin >> nums_str;
        vector<int> nums = parseNums(nums_str);
        
        int l = 0, r = nums.size()-1, d = 1;
        bool is_error = false;
        for (char c: cmd) {
            if (c == 'R') {
                d *= -1;
                continue;
            }
            if (c == 'D') {
                if (d > 0) l++;
                else r--;

                if (l > r+1) {
                    is_error = true;
                    break;
                }
            }
        }

        if (is_error) cout << "error" << '\n';
        else {
            cout << '[';
            if (d > 0) {
                for(int i = l; i <= r; i++) {
                    cout << nums[i];
                    if (i < r) cout << ',';
                }
            } else {
                for(int i = r; i >= l; i--) {
                    cout << nums[i];
                    if (i > l) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}

vector<int> parseNums(string strs) {
    vector<int> ret;
    
    int p = 0, ep = 0;
    while(p < strs.size()) {
        if (strs[ep] == '[') {
            p++; ep = p;
            continue;
        }
        
        if (strs[ep] == ',' || strs[ep] == ']') {
            if (ep > p) {
                string v = strs.substr(p, ep-p);
                ret.push_back(stoi(v));
            }

            p = ep+1;
            ep = p;
        } else {
            ep++;
        }
    }

    return ret;
}