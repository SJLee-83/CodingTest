#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

const int INF = 2e9;
int N, M, P;

vector<pair<int, int>> adj[1005];
vector<pair<int, int>> revAdj[1005];
int dist[1005];
int dist2[1005];

void dijkstra(int cp) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[cp] = 0;
	pq.push({ 0, cp });

	while (!pq.empty()) {
		int currTime = pq.top().first;
		int currNode = pq.top().second;
		pq.pop();

		if (dist[currNode] < currTime) continue;

		for (int i = 0; i < revAdj[currNode].size(); i++) {
			int nextNode = revAdj[currNode][i].second;
			int nextTime = revAdj[currNode][i].first;

			int spendTime = currTime + nextTime;

			if (spendTime < dist[nextNode]) {
				dist[nextNode] = spendTime;
				pq.push({ spendTime, nextNode });
			}
		}
	}
}

void secondDijkstra(int cp) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist2[cp] = 0;
	pq.push({ 0, cp });

	while (!pq.empty()) {
		int currTime = pq.top().first;
		int currNode = pq.top().second;
		pq.pop();

		if(dist2[currNode] < currTime) continue;

		for (int i = 0; i < adj[currNode].size(); i++) {
			int nextNode = adj[currNode][i].second;
			int nextTime = adj[currNode][i].first;

			int spendTime = currTime + nextTime;

			if (spendTime < dist2[nextNode]) {
				dist2[nextNode] = spendTime;
				pq.push({ spendTime, nextNode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> P;
	for (int i = 0; i < M; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adj[s].push_back({ t, e });
		revAdj[e].push_back({ t, s });
	}

	fill(dist, dist + 1005, INF);
	fill(dist2, dist2 + 1005, INF);
	
	dijkstra(P);
	secondDijkstra(P);

	int maxTime = 0;
	
	for (int i = 1; i <= N; i++) {
		if (i == P) continue;
		if (dist[i] != INF && dist2[i] != INF) {
			if (maxTime < dist[i] + dist2[i]) maxTime = dist[i] + dist2[i];
		}
	}

	cout << maxTime;
}