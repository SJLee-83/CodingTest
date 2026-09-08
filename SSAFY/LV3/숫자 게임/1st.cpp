#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int cnt = 0;
    int len = A.size();
    vector<bool> allo(len, false);


    sort(B.begin(), B.end());

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(B[i] > A[j] && !allo[j]) {
                cnt++;
                allo[j] = true;
                break;
            }
        }
    }

    return cnt;
}