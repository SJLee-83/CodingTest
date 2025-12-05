def solution(new_id):
    # 1단계: 모든 대문자를 대응되는 소문자로 치환
    answer = new_id.lower()
    
    # 2단계: 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거
    # (허용된 문자만 필터링해서 다시 합침)
    filtered_answer = ''
    for char in answer:
        if char.isalnum() or char in ['-', '_', '.']:
            filtered_answer += char
    answer = filtered_answer
    
    # 3단계: 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
    while '..' in answer:
        answer = answer.replace('..', '.')
    
    # 4단계: 마침표(.)가 처음이나 끝에 위치한다면 제거
    answer = answer.strip('.')
    
    # 5단계: 빈 문자열이라면, "a"를 대입
    if not answer: # if answer == '': 와 동일
        answer = 'a'
    
    # 6단계: 길이가 16자 이상이면, 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    if len(answer) >= 16:
        answer = answer[:15]
        # 제거 후 마침표(.)가 끝에 위치한다면 제거
        answer = answer.rstrip('.')
    
    # 7단계: 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때까지 반복해서 끝에 붙임
    while len(answer) < 3:
        answer += answer[-1]
        
    return answer

# 정규표현식 풀이(참고용)
# import re

# def solution(new_id):
#     # 1단계
#     new_id = new_id.lower()
    
#     # 2단계: 소문자, 숫자, -, _, . 빼고 다 제거
#     new_id = re.sub(r'[^a-z0-9\-_.]', '', new_id)
    
#     # 3단계: .이 2개 이상이면 . 하나로
#     new_id = re.sub(r'\.+', '.', new_id)
    
#     # 4단계: 양 끝 . 제거
#     new_id = re.sub(r'^[.]|[.]$', '', new_id)
    
#     # 5단계: 빈 문자열이면 'a'
#     new_id = 'a' if len(new_id) == 0 else new_id
    
#     # 6단계: 15글자만 남기기 & 끝 . 제거
#     new_id = new_id[:15]
#     new_id = re.sub(r'[.]$', '', new_id)
    
#     # 7단계: 3글자 될 때까지 늘리기
#     while len(new_id) < 3:
#         new_id += new_id[-1]
        
#     return new_id