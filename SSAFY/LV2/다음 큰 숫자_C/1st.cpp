#include <string>
#include <vector>

using namespace std;

string toBinary(int num){
    string st = "";
    while(num > 0){
        st = char('0' + num % 2) + st;
        num /= 2;    
    }
    return st;
}

int oneCnt(string st){
    int cnt = 0;
    
    for(int i = 0; i < st.size(); i++){
        if(st[i] == '1') cnt++;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = n;
    bool isTrue = true;
    
    string nBinary = toBinary(n);
    int nCnt = oneCnt(nBinary);
    
    while(isTrue){
        answer++;
        string aBinary = toBinary(answer);
        int aCnt = oneCnt(aBinary);
        if(nCnt == aCnt) break;
    }
    
    return answer;
}