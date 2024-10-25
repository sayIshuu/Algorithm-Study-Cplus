#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
// ������ �ʸ������� �� ���Ƽ� ������ �� �����ϴ�.
// ���⵵ ���Ҹ� ����غ���.

int a,b,cnt;
long long c,sum;

typedef struct
{
     int to;    //����� ����
     long long value;   //���
} Edge;

vector<Edge> edge[10001];
bool visited[10001];
priority_queue<pair<long long,int>> pq;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> v >> e;
     while(e--)
     {
          cin >> a >> b >> c;
          edge[a].push_back({b,c});
          edge[b].push_back({a,c});
     }

     //1�� ������ ������ �����ϱ� �긦 �������� ��´�.
     visited[1] = true;
     for (int i = 0; i < edge[1].size(); i++)
     {
          pq.push({-edge[1][i].value, edge[1][i].to});
     }

     while(!pq.empty())
     {
          long long value = -pq.top().first;
          int to = pq.top().second;
          pq.pop();

          if(visited[to]) continue;
          visited[to] = true;
          sum += value;
          cnt++;

          for (int i = 0; i < edge[to].size(); i++)
          {
               //�湮���� ���� ������ ť�� �־��ش�.
               if(visited[edge[to][i].to]) continue;
               pq.push({-edge[to][i].value, edge[to][i].to});
          }
          if(cnt == v-1) break;
     }
     cout << sum;

     return 0;
}