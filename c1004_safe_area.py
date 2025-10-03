def solution(board):
    n = len(board)
    # 1. 위험 지역을 표시할 새로운 지도를 0으로 초기화
    danger_map = [[0] * n for _ in range(n)]

    # 2. board를 순회하며 지뢰 찾기
    for r in range(n):
        for c in range(n):
            # 지뢰를 발견하면
            if board[r][c] == 1:
                # 3. 해당 지뢰 주변 3x3 영역을 위험(1)으로 표시
                for i in range(r - 1, r + 2):
                    for j in range(c - 1, c + 2):
                        # 경계 검사: 지도 범위를 벗어나지 않는지 확인
                        if 0 <= i < n and 0 <= j < n:
                            danger_map[i][j] = 1

    # 4. 안전 지역(0)의 개수 세기
    safe_zones = 0
    for r in range(n):
        for c in range(n):
            if danger_map[r][c] == 0:
                safe_zones += 1
    
    return safe_zones