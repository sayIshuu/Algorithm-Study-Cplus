#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph(1001);
bool visited[1001];
int cnt;

int n,m;

void bfs(int a)
{
     queue<int> q;
     q.push(a);

     while(!q.empty())
     {
          int x = q.front();
          visited[x] = true;
          q.pop();

          for (int i = 0; i < graph[x].size(); i++)
          {
               if(visited[graph[x][i]]) continue;
               q.push(graph[x][i]);
               visited[graph[x][i]] = true;
          }
     }

     cnt++;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     for (int i = 0; i < m; i++)
     {
          int a,b;
          cin >> a >> b;
          graph[a].push_back(b);
          graph[b].push_back(a);
     }
     
     for (int i = 1; i <= n; i++)
     {
          if(!visited[i]) bfs(i);
     }

     cout << cnt;

     return 0;
}