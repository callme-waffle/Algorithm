# [level 0] 순서쌍의 개수 - 120836 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/120836) 

### 성능 요약

메모리: 4.23 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 코딩테스트 입문

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2025년 01월 14일 02:03:19

### 문제 설명

<p>순서쌍이란 두 개의 숫자를 순서를 정하여 짝지어 나타낸 쌍으로 (a, b)로 표기합니다. 자연수 <code>n</code>이 매개변수로 주어질 때 두 숫자의 곱이 <code>n</code>인 자연수 순서쌍의 개수를 return하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>1 ≤ n ≤ 1,000,000</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>n</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>20</td>
<td>6</td>
</tr>
<tr>
<td>100</td>
<td>9</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<ul>
<li><code>n</code>이 20 이므로 곱이 20인 순서쌍은 (1, 20), (2, 10), (4, 5), (5, 4), (10, 2), (20, 1) 이므로 6을 return합니다.</li>
</ul>

<p>입출력 예 #2</p>

<ul>
<li><code>n</code>이 100 이므로 곱이 100인 순서쌍은 (1, 100), (2, 50), (4, 25), (5, 20), (10, 10), (20, 5), (25, 4), (50, 2), (100, 1) 이므로 9를 return합니다.</li>
</ul>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges

### TroubleShooting

#### 고려한 예외
  1. n으로 소수가 입력되는 경우 => '23'인 경우를 테스트케이스로 추가하여 통과됨을 확인
  2. while문이 중단되지 않는 경우 => `while(rem > div)`로 설정하여, rem이 줄어든다면 무조건 while이 중단되도록 설정

#### 고려되지 않은 예외
- (GPT) '5'인 경우에서 예외가 발생함을 확인 ('23'은 운좋게 통과된 것이었음)

#### 해결방법
- rem, n, div 모두 int 타입이라 소수 나눗셈 결과인 경우 의도한대로 rem이 바뀌지 않아 while이 늦게 탈출되는 문제가 있음을 확인 => float으로 typecasting하여 문제해결
