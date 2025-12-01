def solution(id_list, report, k):
    # 1. 정답을 담을 딕셔너리 초기화 (모든 유저의 받을 메일 수는 0개로 시작)
    # 힌트: { "muzi": 0, "frodo": 0 ... }
    answer_dict = {id: 0 for id in id_list}
    
    # 2. 누가 누구를 신고했는지 담을 딕셔너리 (Key: 신고당한 사람, Value: 신고한 사람 리스트)
    # 힌트: { "frodo": ["muzi", "apeach"], ... }
    report_log = {id: [] for id in id_list}
    
    # 3. 중복 신고 제거 (set 활용)
    report = set(report)
    
    # 4. 신고 기록 처리
    for rp in report:
        user_id, reported_id = rp.split(" ") # 신고한 사람, 신고당한 사람
        report_log[reported_id].append(user_id) # 신고당한 사람의 기록에 신고자 추가

    # 5. 정지 대상 확인 및 메일 발송 횟수 카운트
    for reported_id, reporters in report_log.items():
        # reporters 리스트의 길이 = 신고당한 횟수
        if len(reporters) >= k:
            # k번 이상 신고당했으면, 신고한 사람들에게 메일 +1
            for reporter in reporters:
                # 여기에 answer_dict[reporter]를 1 증가시키는 코드를 작성하세요.
                answer_dict[reporter] += 1

    # 6. 딕셔너리 값을 id_list 순서대로 배열로 변환
    return list(answer_dict.values())