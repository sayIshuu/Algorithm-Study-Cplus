#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct
{
     int next;
     int take;
}node;
int intensity = 30000000;
int ansSummit = 50001;

//하나하나 찾을 수 없어서서
bool isGate[50001];
bool isSummit[50001];
bool visited[50001];
void dfs(vector<vector<node>>& graph, int now, int tempIntensity, int fromSummit)
{
     if (tempIntensity >= intensity || (isSummit[now] && now != fromSummit))
          return;
     
     if(isGate[now]){
          ansSummit = fromSummit;
          intensity = tempIntensity;
          return;
     }

     for (int i = 0; i < graph[now].size(); i++){
          if (!visited[graph[now][i].next] && graph[now][i].take < intensity){
               visited[graph[now][i].next] = true;
               dfs(graph, graph[now][i].next, max(tempIntensity,graph[now][i].take), fromSummit);
               visited[graph[now][i].next] = false;
          }
     }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
     //일단 리스트 만들기
     vector<vector<node>> graph(n+1);
     for (int i = 0; i < paths.size(); i++)
     {
          graph[paths[i][0]].push_back({paths[i][1],paths[i][2]});
          graph[paths[i][1]].push_back({paths[i][0],paths[i][2]});
     }
    
    // 가중치 기준으로 정렬
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), [](node a, node b) {
            return a.take < b.take;
        });
    }
    
     for(auto& i : gates)
          isGate[i] = true;
     for(auto& i : summits)
          isSummit[i] = true;
     
     sort(summits.begin(), summits.end());
     for(auto& i : summits){
          visited[i] = true;
          dfs(graph, i, 0, i);
          visited[i] = false;
     }
    
     return {ansSummit, intensity};
}