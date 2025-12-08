def solution(board, moves):
    answer = 0
    basket = [] # out 대신 basket이라는 이름이 더 직관적입니다.

    for m in moves:
        col = m - 1
        # 1. 위에서부터 아래로 탐색
        for row in range(len(board)):
            if board[row][col] != 0:
                doll = board[row][col] # 인형을 집음
                board[row][col] = 0    # 2. 집은 자리는 빈칸(0)으로 만듦
                
                # 3. 바구니 로직 (Stack)
                # 바구니가 비어있지 않고, 맨 위의 인형이 방금 집은 인형과 같다면?
                if basket and basket[-1] == doll:
                    basket.pop() # 터트림
                    answer += 2
                else:
                    basket.append(doll) # 쌓음
                
                break # 인형을 하나 집었으면 해당 열 탐색 종료

    return answer