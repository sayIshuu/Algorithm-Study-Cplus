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

     //�켱����ť�� ���ı��� ����Ⱑ �����Ͽ� pair�� ��� = ù��° ���� �������� ����, ���� �� �ι�°���� ������������
     vector<vector<pair<int,int>>> nearList(n+1);
     int distanceFromK[n+1] = {};
     for (int i = 0; i < n+1; i++) distanceFromK[i] = INF;
     distanceFromK[k] = 0;
     pq.push({0,k});
     for (int i = 0; i < e; i++)
     {
          cin >> u >> v >> w;
          //�켱����ť���� �� ������ �°� ����ġ,fromIndex������ �־���
          nearList[u].push_back({w,v});
     }
     
     while(!pq.empty())
     {
          //�������� �����̹Ƿ� ���� �� -�� �����ش�.
          int accumulatedValue = -pq.top().first;
          int currentIndex = pq.top().second;
          pq.pop();

          //�ڱ������ �ִܰŸ��� �̹� �� ª�� ���ŵǾ������� �� �ʿ䵵 ����
          if(accumulatedValue < distanceFromK[currentIndex]) continue;

          for (int i = 0; i < nearList[currentIndex].size(); i++)
          {
               int nextIndex = nearList[currentIndex][i].second;
               int plusValue = nearList[currentIndex][i].first;

               if(distanceFromK[nextIndex] > plusValue + accumulatedValue)
               {
                    distanceFromK[nextIndex] = plusValue + accumulatedValue;
                    //�������� �����̹Ƿ� ���� �� -�� �����ش�.
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