# [level 1] 소수 찾기 - 12921 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12921) 

### 성능 요약

메모리: 4.19 MB, 시간: 11.91 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 75.0<br/>효율성: 25.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 01월 23일 18:50:11

### 문제 설명

<p>1부터 입력받은 숫자 n 사이에 있는 소수의 개수를 반환하는 함수, solution을 만들어 보세요. </p>

<p>소수는 1과 자기 자신으로만 나누어지는 수를 의미합니다.<br>
(1은 소수가 아닙니다.)</p>

<h5>제한 조건</h5>

<ul>
<li>n은 2이상 1000000이하의 자연수입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>10</td>
<td>4</td>
</tr>
<tr>
<td>5</td>
<td>3</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
1부터 10 사이의 소수는 [2,3,5,7] 4개가 존재하므로 4를 반환</p>

<p>입출력 예 #2<br>
1부터 5 사이의 소수는 [2,3,5] 3개가 존재하므로 3를 반환</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## Troubleshooting

### 풀이 시행착오

> 접근방식을 바꾸는 것을 두려워하지 말기!

1. 방법1: '자신보다 작은 수들로 나눠보도록' 구현하고자 함
   - 재귀함수로 함수 내부에는 입력된 n에 대한 소수여부만 판단하고, 나머지 판단은 재귀호출로 위임
     => 시간초과
     ```cpp
        #include <string>
        #include <vector>
        
        using namespace std;
        
        int solution(int n) {
            if (n <= 1) return 0;
            if (n <= 3) return n-1;
            
            int cnt = solution(n-1);
            if (n%2 == 0) return cnt;
            
            for (int i = 3; i < n; i+=2) {
                if (n%i == 0) return cnt;
            }
            return cnt+1;
        }
     ```
2. 방법2: 중복연산 삭제
   - 메모이제이션 적용, 짝수로 나누는로직 for문에서 제외
     => 시간초과
     ```cpp
                #include <string>
                #include <vector>
                
                using namespace std;
                
                vector<int> prime_cnt(1000000, -1);
                
                int solution(int n) {
                    if (n <= 1) {
                        prime_cnt[0] = 0;
                        prime_cnt[1] = 0;
                        return 0;
                    }
                    if (n <= 3) {
                        prime_cnt[2] = 1;
                        prime_cnt[3] = 2;
                        return prime_cnt[n];
                    }
                    
                    if (prime_cnt[n] > -1) return prime_cnt[n];
                    int prev_cnt = solution(n-1);
                
                    if (n%2 == 0) return prev_cnt;
                    for (int i = 3; i < n; i+=2) {
                        if (n%i == 0) {
                            prime_cnt[n] = prev_cnt;
                            return prime_cnt[n];
                        }
                    }
                    prime_cnt[n] = prev_cnt+1;
                    return prime_cnt[n];
                }
     ```
3. 방법3: 접근방식 변경 & '에라토스테네스의 체' 적용
   - 직접 나누는 방식을 버리고, 특정 수의 배수를 지우는 방식으로 코드구현방식 변경
     => 성공
