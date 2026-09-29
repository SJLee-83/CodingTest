#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool cmpSong(pair<int, int>& a, pair<int, int>& b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

bool cmpGenre(pair<int, string>& a, pair<int, string>& b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> sep;
    
    for(int i = 0; i < genres.size(); i++){
        total[genres[i]] += plays[i];
        sep[genres[i]].push_back({plays[i], i});
    }
    
    vector<int, string> order;
    
    for(auto& p : total){
        order.push_back({p.second, p.first});
    }
    
    sort(order.begin(), order.end(), cmpGenre);
    
    
    vector<int> answer;
    return answer;
} // 진행중