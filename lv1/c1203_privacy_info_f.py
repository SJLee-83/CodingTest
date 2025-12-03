def solution(today, terms, privacies):
    answer = []

    # 1. 약관 종류와 유효기간을 딕셔너리로 저장 (검색 속도 향상)
    term_dict = {}
    for term in terms:
        type_str, duration = term.split()
        term_dict[type_str] = int(duration)

    # 2. 날짜를 총 일수로 변환하는 함수 (모든 달은 28일)
    def to_days(date_str):
        year, month, day = map(int, date_str.split('.'))
        return (year * 12 * 28) + (month * 28) + day
    
    # 3. 오늘 날짜를 일수로 변환
    today_days = to_days(today)

    # 4. privacies를 순서대로 확인 (enumerate로 인덱스 함께 가져옴)
    for i, privacy in enumerate(privacies):
        date_str, type_str = privacy.split()
        
        # 수집 일자를 일수로 변환
        collected_days = to_days(date_str)
        
        # 유효 기간(달)을 일수로 변환하여 더함
        # 유효기간이 6달이면, 6 * 28일을 더하면 됨
        expire_days = collected_days + (term_dict[type_str] * 28)
        
        # 5. 오늘 날짜가 유효기간 만료일보다 크거나 같으면 파기 대상
        # (예: 1일 수집, 1달 유효 -> 28일까지 보관 -> 29일(1+28)부터 파기)
        if today_days >= expire_days:
            answer.append(i + 1) # 번호는 1번부터 시작하므로 +1
            
    return answer

    # answer = []
    # # 약관 종류 분류 및 약관 종류에 따른 기한 종료 날짜 계산
    # fds = []
    # for i in terms:
    #     condition, term = i.split(" ")
    #     for j in privacies:
    #         sd, c = j.split(" ")
    #         if condition == c:
    #             year = int(sd[:4])
    #             month = int(sd[5:7]) + int(term)
    #             day = sd[8:]
    #             if month > 12:
    #                 year = year + (month // 12)
    #                 month = month % 12
    #                 if month < 10:
    #                     month = "0" + str(month)
    #             fd = str(year) + "." + str(month) + "." + day
    #             fds.append(fd)

    # # 당일 날짜와 비교해서 파기해야 할 개인정보 출력
    # ty, tm, td = today.split(".")
    # d = 0
    # for k in fds:
    #     d += 1
    #     kty, ktm, ktd = k.split(".")
    #     if int(kty) < int(ty):
    #         answer.append(d)
    #     else:
    #         if int(ktm) < int(tm):
    #             answer.append(d)
    #         else:
    #             if int(ktd) < int(td):
    #                 answer.append(d)

    # return answer