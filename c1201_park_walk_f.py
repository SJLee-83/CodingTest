def solution(park, routes):
    # 1. 공원 크기
    H = len(park)
    W = len(park[0])
    
    # 2. 시작점 찾기 (range 사용 필수!)
    y, x = 0, 0
    for i in range(H):
        for j in range(W):
            if park[i][j] == "S":
                y, x = i, j
                break
                
    # 방향별 이동량 미리 정의 (북, 남, 서, 동) - [세로, 가로]
    # N은 위로 가니까 행(Row) 인덱스가 줄어듭니다.
    op_dirs = {"N": (-1, 0), "S": (1, 0), "W": (0, -1), "E": (0, 1)}

    # 3. 명령 수행
    for route in routes:
        op, n = route.split() # 공백 기준 분리
        n = int(n)            # 거리는 정수로 변환
        
        # 현재 위치 복사 (임시 위치)
        ny, nx = y, x
        is_valid = True # 이동 가능한지 표시하는 깃발
        
        # 한 칸씩 이동하며 검사
        for _ in range(n):
            # 다음 한 칸 이동
            ny += op_dirs[op][0]
            nx += op_dirs[op][1]
            
            # 조건 1: 공원을 벗어나는지 확인
            if not (0 <= ny < H and 0 <= nx < W):
                is_valid = False
                break
                
            # 조건 2: 장애물인지 확인
            if park[ny][nx] == "X":
                is_valid = False
                break

        # 4. 모든 이동이 유효하다면 실제 위치 업데이트
        if is_valid:
            y, x = ny, nx

    return [y, x]