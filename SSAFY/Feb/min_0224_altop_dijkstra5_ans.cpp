#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int V, E, P;
vector<pair<int, int>> stations[5005];

// 시작 역과 기록할 거리 배열을 인자로 받습니다.
void dijkstra(int start, int dist[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({ 0, start }); // {총 이동 거리, 지금 역}

    while (!pq.empty()) {
        int nowDist = pq.top().first;
        int nowSta = pq.top().second;
        pq.pop();

        // [가지치기] 이미 더 짧은 경로로 방문했다면 무시
        if (nowDist > dist[nowSta]) continue;

        for (int i = 0; i < stations[nowSta].size(); i++) {
            int nextDist = stations[nowSta][i].first;
            int nextSta = stations[nowSta][i].second;

            int sumDist = nowDist + nextDist;
            
            // [거리 갱신] 새로운 경로가 더 짧을 때만 갱신하고 큐에 삽입! (타임아웃 방지)
            if (sumDist < dist[nextSta]) {
                dist[nextSta] = sumDist;
                pq.push({ sumDist, nextSta });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> P;
    for (int i = 0; i < E; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        // 지하철 노선은 양방향이므로 양쪽에 다 넣어줍니다.
        stations[s].push_back({ d, e });
        stations[e].push_back({ d, s });
    }

    // 1번 역에서 출발하는 거리 배열과 P번 역에서 출발하는 거리 배열을 따로 만듭니다.
    int dist1[5005];
    int distP[5005];

    // 1번 인덱스부터 쓰므로 V + 1까지 초기화해야 안전합니다.
    fill(dist1, dist1 + V + 1, INF);
    fill(distP, distP + V + 1, INF);

    // 1. 코코네 집(1)에서 출발
    dijkstra(1, dist1);
    
    // 2. 민철 대리네(P)에서 출발
    dijkstra(P, distP);

    // 3. 지각 여부 판단 (1->V 최단경로 == 1->P 최단경로 + P->V 최단경로)
    // 오버플로우 방지를 위해 INF 검사도 해주는 것이 좋습니다.
    if (dist1[V] != INF && dist1[P] != INF && distP[V] != INF) {
        if (dist1[V] == dist1[P] + distP[V]) {
            cout << "OKAY\n";
        } else {
            cout << "SORRY\n";
        }
    } else {
        // 경로가 아예 없는 경우
        cout << "SORRY\n";
    }

    return 0;
}