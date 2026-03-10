# [level 0] A로 B 만들기 - 120886 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/120886) 

### 성능 요약

메모리: 4.22 MB, 시간: 0.05 ms

### 구분

코딩테스트 연습 > 코딩테스트 입문

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 01월 16일 14:06:41

### 문제 설명

<p>문자열 <code>before</code>와 <code>after</code>가 매개변수로 주어질 때, <code>before</code>의 순서를 바꾸어 <code>after</code>를 만들 수 있으면 1을, 만들 수 없으면 0을 return 하도록 solution 함수를 완성해보세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>0 &lt; <code>before</code>의 길이 == <code>after</code>의 길이 &lt; 1,000</li>
<li><code>before</code>와 <code>after</code>는 모두 소문자로 이루어져 있습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>

<p>| before |after| result |  </p>

<p>| --- | --- | --- |<br>
| "olleh" | "hello" | 1 |<br>
| "allpe" | "apple" | 0 |</p>

<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li>"olleh"의 순서를 바꾸면 "hello"를 만들 수 있습니다.</li>
</ul>

<p>입출력 예 #2</p>

<ul>
<li>"allpe"의 순서를 바꿔도 "apple"을 만들 수 없습니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

## 다른 풀이

### 정렬 후 개수 카운트
```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    sort(before.begin(), before.end());
    sort(after.begin(),after.end());

    // before & after를 각각 정렬 -> 알파벳 순으로 정리됨

    if(after == before) return 1;
    // 정렬된 상태에서 둘이 같은지 비교
    // 섞어서 만들 수 있다면 정렬결과는 같아야 하므로 항상 1이 return

    else return 0;
}
```

- 코드의 복잡도를 고려했을 때 훨씬 간단
- sort와 map의 내부 구현 방식에 따라 효율성에는 일부 차이가 있을 것으로 생각
  
