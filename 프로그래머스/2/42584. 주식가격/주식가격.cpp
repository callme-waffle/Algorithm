#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); i++) {
        for (int j = i+1; j < prices.size(); j++) {
            answer[i] = j-i;
            if (prices[i] > prices[j]) break;
        }
    }
    return answer;
}