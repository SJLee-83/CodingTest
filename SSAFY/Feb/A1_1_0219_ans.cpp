#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, lastSem;
vector<int> arr[105]; 
int inDegree[105]; 
vector<int> startS; 
bool visited[105]; 

void bfs() {
    queue<pair<int, int>> q; 

    for (int i = 0; i < startS.size(); i++) {
        q.push({ startS[i], 1 });
        visited[startS[i]] = true;
    }

    while (!q.empty()) {
        int nowSub = q.front().first;
        int nowSem = q.front().second;
        q.pop();

        lastSem = nowSem;

        for (int i = 0; i < arr[nowSub].size(); i++) {
            int nextSub = arr[nowSub][i];
            
            inDegree[nextSub]--;

            if (!visited[nextSub] && inDegree[nextSub] == 0) {
                visited[nextSub] = true;
                q.push({ nextSub, nowSem + 1 });
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (test_case = 1; test_case <= T; test_case++)
    {
        cin >> N;
        startS.clear();
        memset(visited, false, sizeof(visited));
        memset(inDegree, 0, sizeof(inDegree));
        lastSem = 0;

        for (int i = 0; i <= N; i++) {
            arr[i].clear();
        }

        for (int i = 1; i <= N; i++) {
            int u;
            cin >> u;
            if (u == 0) startS.push_back(i);

            for (int j = 0; j < u; j++) {
                int num;
                cin >> num;
                arr[num].push_back(i);
                inDegree[i]++;
            }
        }

        bfs();

        int possible = lastSem;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                possible = -1;
                break;
            }
        }

        cout << "#" << test_case << " " << possible << endl;
    }

    return 0;
}