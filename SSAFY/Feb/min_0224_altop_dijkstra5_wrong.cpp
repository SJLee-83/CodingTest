#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int V, E, P;
vector<pair<int, int>>stations[5005];
int dist[5005];
bool canTake = false;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 }); // 총 이동 거리, 지금 역

    while (!pq.empty()) {
        int nowDist = pq.top().first;
        int nowSta = pq.top().second;
        pq.pop();

        if (nowDist > dist[nowSta]) continue;
        if (nowDist == dist[nowSta] && nowSta != P) continue;
        if (nowSta == P) canTake = true;
        dist[nowSta] = nowDist;

        for (int i = 0; i < stations[nowSta].size(); i++) {
            int nextDist = stations[nowSta][i].first;
            int nextSta = stations[nowSta][i].second;

            int sumDist = nowDist + nextDist;
            pq.push({ sumDist, nextSta });
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

        stations[s].push_back({ d, e });
        stations[e].push_back({ d, s });
    }
    fill(dist, dist + V, INF);
    dijkstra();

    cout << canTake;
}