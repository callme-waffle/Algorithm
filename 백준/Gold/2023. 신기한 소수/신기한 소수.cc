#include <iostream>
#include <vector>

using namespace std;

int n = 10, m;
int v = 0, cnt = 0; // 자리 별 선택한 값

vector<bool> is_prime(10001, true); // is_prime[i]: i가 소수인지 여부 표시
vector<int> primes; // 소수목록

void dupPerm();
void createPrimeBase();
bool isPrime(int v);

int main() {
    createPrimeBase();
    cin >> m;
    dupPerm();
}

void dupPerm() {
    if (cnt == m) {
        cout << v << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        v*=10; v+=i; cnt++;
        if(isPrime(v)) dupPerm();
        v/=10; cnt--;
    }
}

// 8자리까지 계산해줘야 하므로, 에라토스테네스의 체를 그냥 적용할 수는 없음

// 다만, 생성된 숫자(이하 'P')가 합성수라면, A*B(A<=B)가 가능하며, 이때 A는 항상 sqrt(P)보다 작음
// ㄴ ex) 24의 경우, 4*6이 A가 가장 큰 경우이며, 이때 4는 sqrt(24)인 4.89... 보다 작음

// 따라서 sqrt(99999999)까지만 에라토스테네스의 체를 구성했을 때 메모리 초과가 발생하는지 공간복잡도를 먼저 계산하고,
// 이후 코드를 작성하면 됨

void createPrimeBase() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 2; i <= 10000; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = 2; i*j <= 10000; j++) {
            is_prime[i*j] = false;
        }
    }
}

bool isPrime(int a) {
    if (a <= 10000) return is_prime[a];
    for (int& prime: primes) {
        if (a % prime == 0) return false;
    }

    return true;
}