#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> sp;

int f(int n);

int solution(int n) {
    sp = vector<int>(n+1, -1);
    sp[0] = 0; sp[1] = 1;
    
    return f(n);
}
int f(int n) {
    if (sp[n] == -1) sp[n] = (f(n-1) + f(n-2))%1234567;
    return sp[n];
}