# [level 2] 가장 큰 수 - 42746 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42746#) 

### 성능 요약

메모리: 10.5 MB, 시간: 383.24 ms

### 구분

코딩테스트 연습 > 정렬

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 01월 29일 22:49:00

### 문제 설명

<p>0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.</p>

<p>예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고, 이중 가장 큰 수는 6210입니다.</p>

<p>0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한 사항</h5>

<ul>
<li>numbers의 길이는 1 이상 100,000 이하입니다.</li>
<li>numbers의 원소는 0 이상 1,000 이하입니다.</li>
<li>정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>numbers</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[6, 10, 2]</td>
<td>"6210"</td>
</tr>
<tr>
<td>[3, 30, 34, 5, 9]</td>
<td>"9534330"</td>
</tr>
</tbody>
      </table>
<hr>

<p>※ 공지 - 2021년 10월 20일 테스트케이스가 추가되었습니다.</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 풀이 시행착오
1. 앞자리가 클수록, 앞자리비교가 동일 시 차이나는 길이만큼의 영역비교시 더 큰값이 먼저오도록 설계 => 테스트케이스 시간초과 & 풀이오류
2. (풀이확인: https://esoongan.tistory.com/103) 자리수를 4자리씩 채워 비교하도록 설계 => 테스트케이스 1개 실패
3. (풀이확인: https://school.programmers.co.kr/questions/57427) 입력으로 0만 오는경우를 고려하도록 설계 => 정답

## 다른풀이 분석

### 정렬 시 문자열로 만들어서 비교하기
```cpp
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const string &a, const string &b)
{
    // 입력된 2개의 문자열을 다른 방향으로 합쳐보고, 더 큰값을 만들어내는 조합으로 정렬
    if (b + a < a + b)
        return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> strings;

    for (int i : numbers)
        strings.push_back(to_string(i));

    sort(strings.begin(), strings.end(), compare);

    for (auto iter = strings.begin(); iter < strings.end(); ++iter)
        answer += *iter;

    if (answer[0] == '0')
        answer = "0";

    return answer;
}
```

## 느낀점
- 특정 조건에 따라 정렬이 필요한 경우, 최대한 정렬조건을 단순화하는 과정을 진행한 후 코드작성 시작하기
- 문제가 풀리지 않는다면, 문제의 근원부터 다시 살펴보기 (풀이이론의 기초, 문제에서 최종적으로 요구하는 정답 등)
