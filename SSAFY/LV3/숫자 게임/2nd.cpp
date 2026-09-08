#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B){
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int len = A.size();
    int cnt = 0;
    int a = 0;

    for(int i = 0; i < len; i++){
        if(B[i] > A[a]){
            cnt++;
            a++;
        }
    }

    return cnt;
}