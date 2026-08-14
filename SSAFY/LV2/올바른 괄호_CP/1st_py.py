def solution(s):
    answer = True
    
    cnt = 0;
    
    for i in range(len(s)):
        if (i == 0 and s[i] == ")") or cnt < 0:
            return False
        
        else:
            if s[i] == "(":
                cnt += 1
            elif s[i] == ")":
                cnt -= 1
                
    if cnt > 0: return False
        
    return True