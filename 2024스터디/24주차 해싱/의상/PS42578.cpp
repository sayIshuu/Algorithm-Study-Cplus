#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for(auto &c : clothes)
        m[c[1]]++;
    
    for(auto &it : m)
        answer *= (it.second + 1);
    return answer-1;
}