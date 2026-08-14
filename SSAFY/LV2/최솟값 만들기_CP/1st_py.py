def solution(A,B):
    answer = 0

    A = sorted(A)
    B = sorted(B)
    
    for i in range(len(A)):
        answer += A[i] * B[len(A) - 1 - i]

    return answer