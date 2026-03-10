#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> a;
    for (int num: nums) a.insert(num);
    
    int max_pick = nums.size()/2;
    return a.size() > max_pick ? max_pick : a.size();
}