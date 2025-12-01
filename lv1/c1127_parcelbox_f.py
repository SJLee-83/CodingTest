def solution(n, w, num):
    answer = 0
    
    # 1. num 상자의 위치(층, 열) 구하기
    row = (num - 1) // w
    col = (num - 1) % w
    
    # 홀수 층(1, 3, 5...)은 역순이므로 열 위치를 반전시킴
    if row % 2 == 1:
        col = w - 1 - col
        
    # 2. 현재 층부터 꼭대기 층까지 반복하며 같은 열(col) 확인
    # 최대 층은 (n-1) // w 입니다.
    max_row = (n - 1) // w
    
    for r in range(row, max_row + 1):
        # 해당 층(r)의 같은 열(col)에 있는 상자 번호 계산
        if r % 2 == 0:
            # 짝수 층: 정방향
            box_num = r * w + col + 1
        else:
            # 홀수 층: 역방향
            box_num = r * w + (w - 1 - col) + 1
            
        # 3. 그 상자가 창고에 존재하는지(n 이하인지) 확인
        if box_num <= n:
            answer += 1
            
    return answer