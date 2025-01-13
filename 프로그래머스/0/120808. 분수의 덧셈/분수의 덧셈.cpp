#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    int numer = (numer1*denom2)+(denom1*numer2);
    int denom = denom1 * denom2;
    
    int big = (numer > denom) ? numer : denom;
    int div = 2;
    while (big >= div) {
        while(numer%div == 0 && denom%div == 0) {
            numer /= div;
            denom /= div;
        }
        div++;
    }
    
    answer.push_back(numer);
    answer.push_back(denom);
    
    return answer;
}