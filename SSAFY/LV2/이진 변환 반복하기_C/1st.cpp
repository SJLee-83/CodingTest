#include <string>
#include <vector>

using namespace std;

int biChange = 0;
int zeroSum = 0;

int reBi(int num){
    int bi = 1;
    
    for(int i = 1; i < num; i++){
        bi *= 2;
    }
    return bi;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            zeroSum++;
        }
        else{
            answer.push_back(1);
        }
    }
    
    while(1){
        if(answer.size() == 1){
            return answer
        }
        else{
            int preResult = 1;
            
            // 이진 -> 십진
            for(int i = 1; i < answer.size(); i++){
                preResult += reBi(i);
            }
            
            // 십진 -> 이진
            
            
            while(preResult != 1){
                preResult %= 2;
                
            }
            
        }
    }
    
    return answer;
}