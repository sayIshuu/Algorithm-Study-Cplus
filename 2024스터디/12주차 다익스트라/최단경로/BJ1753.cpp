#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 9999999
using namespace std;

int n,e,k;
int u,v,w;
priority_queue<pair<int,int>> pq;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> e >> k;

     //우선순위큐의 정렬기준 세우기가 복잡하여 pair를 사용 = 첫번째 기준 내림차순 정렬, 같을 시 두번째기준 내림차순정렬
     vector<vector<pair<int,int>>> nearList(n+1);
     int distanceFromK[n+1] = {};
     for (int i = 0; i < n+1; i++) distanceFromK[i] = INF;
     distanceFromK[k] = 0;
     pq.push({0,k});
     for (int i = 0; i < e; i++)
     {
          cin >> u >> v >> w;
          //우선순위큐에서 들어간 순서에 맞게 가중치,fromIndex순으로 넣어줌
          nearList[u].push_back({w,v});
     }
     
     while(!pq.empty())
     {
          //내림차순 정렬이므로 출입 시 -를 곱해준다.
          int accumulatedValue = -pq.top().first;
          int currentIndex = pq.top().second;
          pq.pop();

          //자기까지의 최단거리가 이미 더 짧게 갱신되어있으면 볼 필요도 없음
          if(accumulatedValue < distanceFromK[currentIndex]) continue;

          for (int i = 0; i < nearList[currentIndex].size(); i++)
          {
               int nextIndex = nearList[currentIndex][i].second;
               int plusValue = nearList[currentIndex][i].first;

               if(distanceFromK[nextIndex] > plusValue + accumulatedValue)
               {
                    distanceFromK[nextIndex] = plusValue + accumulatedValue;
                    //내림차순 정렬이므로 출입 시 -를 곱해준다.
                    pq.push({-distanceFromK[nextIndex], nextIndex});
               }
          }
     }

     for (int i = 1; i <= n; i++)
     {
          if(distanceFromK[i] == INF)
               cout << "INF" << '\n';
          else
               cout << distanceFromK[i] << '\n';
     }
     

     return 0;
}