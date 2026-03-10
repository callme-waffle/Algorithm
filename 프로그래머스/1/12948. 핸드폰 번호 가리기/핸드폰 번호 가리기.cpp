#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int pns = phone_number.size();
    for (int i = 1; i <= pns; i++) {
        if (i <= 4) continue;
        phone_number[pns-i] = '*';
    }
    return phone_number;
}