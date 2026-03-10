#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    auto swap_point = num_list.begin();
    auto end_point = num_list.end()-1;
    int tmp;
    
    while(swap_point < end_point) {
        tmp = *swap_point;
        *swap_point = *end_point;
        *end_point = tmp;
        
        swap_point++;
        end_point--;
    }
    return num_list;
}
