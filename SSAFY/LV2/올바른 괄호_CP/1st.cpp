#include<string>
#include <iostream>

using namespace std;

// ios::sync_with_stdio(false);
// cin.tie(NULL);
// cout.tie(NULL);

string s;
int cnt = 0;

bool dec(string s){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        
        if(cnt < 0){
            return false;
        }
    }
    if(cnt == 0) return true;
    else return false;   
}

int main(){
    cin >> s;
    
    return dec(s);
}