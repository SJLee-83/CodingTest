def solution(a, b, c, d):
    dices = sorted([a, b, c, d])
    p, q, r, s = dices[0], dices[1], dices[2], dices[3]

    # Case 1: 네 숫자가 모두 같을 때
    if p == s:
        return 1111 * p
    
    # Case 2: 세 숫자가 같을 때
    elif p == r or q == s:
        # p, p, p, q 형태 (p==r)
        if p == r:
            return (10 * p + s) ** 2
        # q, p, p, p 형태 (q==s)
        else:
            return (10 * q + p) ** 2

    # Case 3: 두 개씩 같은 값이 나올 때
    elif p == q and r == s:
        return (p + r) * abs(p - r)

    # Case 4: 두 숫자만 같을 때
    elif p == q:
        return r * s
    elif q == r:
        return p * s
    elif r == s:
        return p * q
        
    # Case 5: 네 숫자가 모두 다를 때
    else:
        return p