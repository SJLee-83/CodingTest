def solution(num, total):
    answer = []
    # 반복문 대신 등차수열로 계산하여 total에서 차감
    for i in range(0, num):
        total -= i

    start_num = total / num
    
    for j in range(0, num):
        answer.append(start_num + j)

    return answer


# def solution(num, total):
#     return [(total - (num * (num - 1) // 2)) // num + i for i in range(num)]