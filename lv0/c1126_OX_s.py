def solution(quiz):
    answer = []

    for formula in quiz:
    # for q in quiz:
    #         X, op, Y, eq, Z = q.split()
    #         X, Y, Z = int(X), int(Y), int(Z)        

        parts = formula.split(" ")
        x = int(parts[0])
        op = parts[1]
        y = int(parts[2])
        z = int(parts[4])

        if (op == "+" and x + y == z) or (op == "-" and x - y == z):
            answer.append("O")
        else:
            answer.append("X")
    return answer

# def solution(quiz):
#     answer = []
#     for q in quiz:
#         # "=" 을 기준으로 좌변(수식)과 우변(결과값)을 나눔
#         expression, result = q.split("=")
        
        # eval() 함수는 문자열로 된 수식을 실제로 계산 
#         # 좌변을 계산한 값(eval)과 우변의 값(int)이 같은지 비교
#         if eval(expression) == int(result):
#             answer.append("O")
#         else:
#             answer.append("X")
#     return answer