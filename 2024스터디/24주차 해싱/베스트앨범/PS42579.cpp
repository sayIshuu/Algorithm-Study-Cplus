#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<string, int> cnt;
unordered_map<string, vector<pair<int,int>>> m;

bool compare(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for(int i = 0; i < genres.size(); i++){
        m[genres[i]].push_back({plays[i],i});
        cnt[genres[i]] += plays[i];
    }

    vector<pair<string, int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), compare);


    // m의 value를 plays 내림차순으로 정렬
    for(auto &it : m){
        sort(it.second.begin(), it.second.end(), greater<pair<int,int>>());
    }

    for(auto &it : v){
        if(m[it.first].size() == 1){
            answer.push_back(m[it.first][0].second);
        }
        else{
            answer.push_back(m[it.first][0].second);
            answer.push_back(m[it.first][1].second);
        }
    }

    return answer;
}