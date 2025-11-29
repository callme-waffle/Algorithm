# 이미 계산한 값을 저장할 딕셔너리 (전역 혹은 함수 내 사용)
memo = {}

def poss(n, m):
    # 메모리에 있으면 반환
    if (n, m) in memo:
        return memo[(n, m)]
    
    # [기저 사례]
    # N과 M이 같으면 다리를 잇는 방법은 1가지뿐
    if n == m:
        return 1
    # N이 0이면(혹은 1개를 선택하는데 M개 중 고를 때 등) -> 여기선 N=0이 성공 케이스
    if n == 0: 
        return 1
    # N=1이면 M개 중 하나를 고르는 것이므로 M가지
    if n == 1:
        return m
        
    # [점화식] mCn = m-1Cn + m-1Cn-1
    # (이번 오른쪽 사이트를 안 쓰는 경우) + (이번 오른쪽 사이트를 쓰는 경우)
    result = poss(n, m-1) + poss(n-1, m-1)
    
    memo[(n, m)] = result
    return result

T = int(input())
for _ in range(T):
    lc, rc = map(int, input().split())
    memo = {} # 테스트 케이스마다 초기화 권장 (물론 안 해도 값은 같지만 메모리 관리 차원)
    print(poss(lc, rc))