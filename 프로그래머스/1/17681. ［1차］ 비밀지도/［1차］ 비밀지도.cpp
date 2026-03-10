#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answers;
    for (int i = 0; i < n; i++) {
        int& a = arr1[i], b = arr2[i];
        string ans = "";
        for (int j = 0; j < n; j++) {
            ans.insert(0, 1, (a%2 || b%2) ? '#' : ' ');
            a = a >> 1;
            b = b >> 1;
        }
        answers.push_back(ans);
    }
    return answers;
}