#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if (price < 100000) return price;
    
    int rate = 5;
    if (price >= 300000) rate *= 2;
    if (price >= 500000) rate *= 2;
    
    return price * (100-rate)/100;
}