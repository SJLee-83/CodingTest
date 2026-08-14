import string

def solution(s):
    answer = list(map(string, s.split()))
    
    for i in range(len(s)):
        if(answer[i][0] > 'z' or answer[i][0] < 'a') and (answer[i][0] > 'Z' or answer[i][0] < 'A'):
            for j in range(1, len(answer[i])):
                if(answer[i][j] >= 'A' and answer[i][j] <= 'Z'):
                    answer[i][j] += 32
    
        else:
            if(answer[i][0] >= 'a' and answer[i][0] <= 'z'):
                answer[i][0] -= 32
            for j in range(1, len(answer[i])):
                if(answer[i][j] >= 'A' and answer[i][j] <= 'Z'):
                    answer[i][j] += 32
                    
    return answer