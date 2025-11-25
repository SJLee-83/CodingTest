def solution(numer1, denom1, numer2, denom2):
    answer = []
    numer = numer1*denom2 + numer2*denom1
    denom = denom1*denom2

    # 최대 공약수 구하는 계산식    
    a, b = numer, denom
    while b > 0:
        a, b = b, a%b
    gcd = a

    answer = [numer//gcd, denom//gcd]
    return answer