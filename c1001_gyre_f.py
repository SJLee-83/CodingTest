def solution(n):
    # 1. n x n 배열을 0으로 초기화
    answer = [[0] * n for _ in range(n)]

    # 2. 방향 벡터 (우, 하, 좌, 상)
    dr = [0, 1, 0, -1]
    dc = [1, 0, -1, 0]

    # 3. 초기 변수 설정
    r, c = 0, 0
    direction = 0  # 0: 오른쪽

    # 4. 1부터 n*n까지 반복
    for num in range(1, n * n + 1):
        # 현재 위치에 숫자 할당
        answer[r][c] = num

        # 다음 위치 계산
        nr = r + dr[direction]
        nc = c + dc[direction]

        # 방향 전환 검사: 벽에 부딪히거나 이미 채워진 칸을 만나면
        if nr < 0 or nr >= n or nc < 0 or nc >= n or answer[nr][nc] != 0:
            direction = (direction + 1) % 4

        # 현재 위치 업데이트
        r += dr[direction]
        c += dc[direction]

    return answer