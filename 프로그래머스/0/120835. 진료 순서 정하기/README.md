# [level 0] 진료 순서 정하기 - 120835 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/120835) 

### 성능 요약

메모리: 3.75 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 코딩테스트 입문

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 01월 16일 12:52:16

### 문제 설명

<p>외과의사 머쓱이는 응급실에 온 환자의 응급도를 기준으로 진료 순서를 정하려고 합니다. 정수 배열 <code>emergency</code>가 매개변수로 주어질 때 응급도가 높은 순서대로 진료 순서를 정한 배열을 return하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>중복된 원소는 없습니다.</li>
<li>1 ≤ <code>emergency</code>의 길이 ≤ 10</li>
<li>1 ≤ <code>emergency</code>의 원소 ≤ 100</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>emergency</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>[3, 76, 24]</td>
<td>[3, 1, 2]</td>
</tr>
<tr>
<td>[1, 2, 3, 4, 5, 6, 7]</td>
<td>[7, 6, 5, 4, 3, 2, 1]</td>
</tr>
<tr>
<td>[30, 10, 23, 6, 100]</td>
<td>[2, 4, 3, 5, 1]</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li><code>emergency</code>가 [3, 76, 24]이므로 응급도의 크기 순서대로 번호를 매긴 [3, 1, 2]를 return합니다.</li>
</ul>

<p>입출력 예 #2</p>

<ul>
<li><code>emergency</code>가 [1, 2, 3, 4, 5, 6, 7]이므로 응급도의 크기 순서대로 번호를 매긴 [7, 6, 5, 4, 3, 2, 1]를 return합니다.</li>
</ul>

<p>입출력 예 #3</p>

<ul>
<li><code>emergency</code>가 [30, 10, 23, 6, 100]이므로 응급도의 크기 순서대로 번호를 매긴 [2, 4, 3, 5, 1]를 return합니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 다른풀이 분석

### map의 key 정렬특성을 활용한 풀이
```cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> emergency) {
    auto amt = map<int, int>();
    for (auto& e : emergency) { amt[e]; }
    // ㄴ 'amt' map에 'e'를 key로 입력
    // => map은 기본적으로 key저장 시 오름차순 정렬하여 저장

    auto order = amt.size();
    for (auto& e : amt) { e.second = order--; }
    // ㄴ 이미 정렬되어있는 상태이므로, 정렬된 원소 (=key)의 value로 순서를 입력
    // ㄴ 문제에서 높은 우선순위일 수록 낮은 숫자가 오도록 하여 `order--` 형태로 작성

    for (auto& e : emergency) { e = amt[e]; }
    // ㄴ 원본 vector에 정렬결과 덮어씌우기 => 공각복잡도 최소화
    return emergency;
}
```
