def solution(schedules, timelogs, startday):
    answer = 0
    
    # 직원 수만큼 반복
    for i in range(len(schedules)):
        # 1. 인정 마감 시각(deadline) 구하기
        hope_time = schedules[i]
        h = hope_time // 100
        m = hope_time % 100
        
        m += 10 # 10분을 더해줍니다.
        if m >= 60: # 분이 60을 넘어가면
            h += 1  # 시를 1 올리고
            m -= 60 # 분에서 60을 뺍니다.
            
        deadline = h * 100 + m
        
        # 2. 일주일 출근 기록 검사
        is_success = True # 상품 수령 가능 여부 (일단 성공으로 가정)
        
        for j in range(7):
            # 3. 요일 계산 (주말이면 패스)
            # startday는 1(월)~7(일)입니다.
            # (startday + j) % 7 결과를 보면:
            # 월(1)%7=1 ... 금(5)%7=5, 토(6)%7=6, 일(7)%7=0
            current_day_mod = (startday + j) % 7
            
            if current_day_mod == 6 or current_day_mod == 0:
                continue # 토요일(6)이나 일요일(0)은 검사하지 않음
            
            # 4. 지각 여부 확인
            if timelogs[i][j] > deadline:
                is_success = False # 한 번이라도 늦으면 실패
                break # 더 이상 확인할 필요 없음
        
        # 일주일 검사가 끝난 후에도 성공 상태라면 카운트 증가
        if is_success:
            answer += 1
            
    return answer