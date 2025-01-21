#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photos) {
    map<string, int> yearn;
    for (int i = 0; i < name.size(); i++) {
        yearn[name[i]] = yearning[i];
    }
    
    vector<int> res;
    for (vector<string>& photo: photos) {
        int sum = 0;
        for (string id: photo) {
            sum += yearn[id];
        }
        res.push_back(sum);
    }
    
    return res;
}