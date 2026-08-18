#include <string>
#include <vector>

using namespace std;

string toBinary(int n){
    string s = "";
    while(n > 0){
        s = char('0' + n % 2) + s;
        n /= 2;
    }
    
    return s;
}

vector<int> solution(string s) {
    int zeroCnt = 0;
    int changeCnt = 0;
    
    while(s != "1"){
        changeCnt++;
        int ones = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                zeroCnt++;
            }
            else{
                ones++;
            }
        }
        s = toBinary(ones);
    }
    
    
    return {changeCnt, zeroCnt};
}