#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, lastSem;
vector<int> arr[105]; // 선수과목 연결-> 선수과목 | 과목
vector<int> revArr[105]; // 선수과목 연결-> 과목 | 선수과목
vector<int> startS; // 선수과목 없는 과목들
int revArrCount[105];
bool visited[105]; // 수강한 과목 처리

void bfs() {
    queue<pair<int, int>> q; // 과목, 학기

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
            revArrCount[nextSub]++;

            if (!visited[nextSub] && revArr[nextSub].size() == revArrCount[nextSub]) {
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
        arr[105].clear();
        revArr[105].clear();
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= N; i++) {
            int u;
            cin >> u;
            if (u == 0) startS.push_back(i); // 첫 학기 구하고

            for (int j = 0; j < u; j++) {
                int num;
                cin >> num;
                arr[num].push_back(i);
                revArr[i].push_back(num);
            }
        }
        
        bfs();

        int possible;

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                possible = -1;
                break;
            }
            else possible = lastSem;
        }

        cout << "#" << test_case << " " << possible << endl;
    }

    return 0;
}