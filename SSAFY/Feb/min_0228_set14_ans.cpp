#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, partNum;
int board[15][15];
int partsNum[15][15]; 
bool visited[15][15]; 

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// 케이블(간선) 정보를 담을 구조체
struct Edge {
    int dist; // 케이블 길이
    int u;    // 부품 A
    int v;    // 부품 B
    
    // 오름차순 정렬을 위한 연산자 오버로딩
    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }
};

vector<Edge> edges; // 가능한 모든 케이블 후보를 담을 배열

// 유니온 파인드를 위한 부모(보스) 배열
int parent[10];

// Find: 최고 보스 찾기
int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

// Union: 두 부품을 같은 팀으로 합치기 (합치기에 성공하면 true, 이미 같은 팀이면 false)
bool unionNodes(int a, int b) {
    int rootA = findParent(a);
    int rootB = findParent(b);
    
    if (rootA == rootB) return false; // 이미 같은 팀 (사이클 발생)
    
    parent[rootB] = rootA; // 팀 합치기
    return true;
}

// 부품 번호 매기기 (작성하신 Flood Fill 로직)
void ff(int y, int x, int partNum) {
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;
    partsNum[y][x] = partNum;

    while (!q.empty()) {
        int nowY = q.front().first;
        int nowX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = nowY + dy[i];
            int nx = nowX + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (board[ny][nx] == 0 || visited[ny][nx]) continue;
            
            visited[ny][nx] = true;
            partsNum[ny][nx] = partNum;
            q.push({ ny, nx });
        }
    }
}

// 한 방향으로 쭉 직진하며 다른 부품을 찾는 함수 (Ray Casting)
void findEdges(int y, int x, int currentPart) {
    for (int i = 0; i < 4; i++) {
        int ny = y;
        int nx = x;
        int dist = 0;

        while (true) {
            ny += dy[i];
            nx += dx[i];

            // 맵을 벗어나면 중단
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) break;

            // 같은 부품을 만나면 중단 (안쪽 깊숙한 곳에서 쏜 레이저가 껍질에 닿은 경우)
            if (partsNum[ny][nx] == currentPart) break;

            // 다른 부품을 만난 경우
            if (partsNum[ny][nx] != 0) {
                // 케이블 길이가 2 이상일 때만 후보에 추가 (문제 조건 C)
                if (dist >= 2) {
                    edges.push_back({ dist, currentPart, partsNum[ny][nx] });
                }
                break; // 다른 부품을 뚫고 갈 수는 없으므로 중단
            }

            // 빈 공간(0)이면 거리 증가 후 계속 직진
            dist++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // 1. 부품 고유 번호 매기기 (Flood Fill)
    partNum = 0; 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                partNum++;
                ff(i, j, partNum);
            }
        }
    }

    // 2. 가능한 모든 케이블 조합 찾기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (partsNum[i][j] != 0) {
                // 부품이 있는 모든 칸에서 상하좌우로 레이저를 쏴봄
                findEdges(i, j, partsNum[i][j]);
            }
        }
    }

    // 3. 크루스칼 알고리즘 시작
    // 케이블 길이 오름차순 정렬 (가장 짧은 것부터 쓰기 위해)
    sort(edges.begin(), edges.end());

    // 유니온 파인드 초기화 (처음엔 자기 자신이 보스)
    for (int i = 1; i <= partNum; i++) {
        parent[i] = i;
    }

    int totalLength = 0;
    int connectedEdges = 0;

    for (int i = 0; i < edges.size(); i++) {
        // 사이클이 안 생기게 두 부품을 연결할 수 있다면
        if (unionNodes(edges[i].u, edges[i].v)) {
            totalLength += edges[i].dist;
            connectedEdges++;
        }
        
        // 부품 개수가 P개라면, (P-1)개의 선만 있으면 모두 연결됨
        if (connectedEdges == partNum - 1) break;
    }

    // 4. 모든 부품이 연결되었는지 확인
    if (connectedEdges == partNum - 1) {
        cout << totalLength;
    } else {
        // 불가능한 경우 (문제 조건 출력)
        cout << -1;
    }

    return 0;
}