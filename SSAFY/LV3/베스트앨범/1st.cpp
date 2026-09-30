#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmpGenres(pair<int, string>& a, pair<int, string>& b){
    return a.first > b.first;
}

bool cmpMusic(pair<int, int>& a, pair<int, int>& b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> sep;
    
    for(int i = 0; i < genres.size(); i++){
        total[genres[i]] += plays[i];
        sep[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> cntGenres;
    
    for(auto& p : total){
        cntGenres.push_back({p.second, p.first});
    }
    
    sort(cntGenres.begin(), cntGenres.end(), cmpGenres);
    
    vector<int> answer;
    
    for(int i = 0; i < cntGenres.size(); i++){
        string g = cntGenres[i].second;
        vector<pair<int, int>>& cntMusic = sep[g];
        sort(cntMusic.begin(), cntMusic.end(), cmpMusic);
        for(int j = 0; j < cntMusic.size() && j < 2; j++){
            answer.push_back(cntMusic[j].second);
        }
    }
    
    return answer;
}