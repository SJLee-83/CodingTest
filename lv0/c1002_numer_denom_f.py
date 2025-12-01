import math # math.gcd() 함수를 사용하기 위해 import

def solution(numer1, denom1, numer2, denom2):
    # 1. 두 분수를 더하기 (통분)
    # 분자 = (분자1 * 분모2) + (분자2 * 분모1)
    numer = numer1 * denom2 + numer2 * denom1
    # 분모 = 분모1 * 분모2
    denom = denom1 * denom2

    # 2. 분자와 분모의 최대공약수(GCD) 구하기
    # math.gcd()를 사용하면 매우 간단하게 구할 수 있습니다.
    gcd = math.gcd(numer, denom)

    # # 최대공약수(GCD)를 찾기 위한 반복문
    # # 1부터 분자와 분모 중 작은 값까지 역순으로 반복
    # gcd = 1
    # for i in range(min(numer, denom), 0, -1):
    #     if numer % i == 0 and denom % i == 0:
    #         gcd = i
    #         break # 찾으면 바로 종료

    # 3. 최대공약수로 나누어 기약분수 만들기
    final_numer = numer // gcd
    final_denom = denom // gcd

    return [final_numer, final_denom]