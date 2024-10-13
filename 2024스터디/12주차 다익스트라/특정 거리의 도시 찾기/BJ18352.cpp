#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k,x;

typedef struct
{
     int index;
     int distance;
}node;
bool isPrint;

vector<int> ans;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m >> k >> x;
     vector<vector<int>> v(n+1);
     bool visited[n+2] = {}; //지역변수일때 초기화 잊지말기

     for (int i = 0; i < m; i++)
     {
          int a,b;
          cin >> a >> b;
          v[a].push_back(b);
     }

     queue<node> q;
     visited[x] = true;
     q.push({x,0});

     while(!q.empty())
     {
          int index = q.front().index;
          int dis = q.front().distance;
          q.pop();

          if(dis == k){ 
               ans.push_back(index);
               isPrint = true;
          }
          else if(dis > k) break;

          for (int i = 0; i < v[index].size(); i++)
          {
               if(visited[v[index][i]]) continue;
               
               visited[v[index][i]] = true;
               q.push({v[index][i], dis+1});
          }
     }

     if(!isPrint) cout << -1;
     else{
          sort(ans.begin(), ans.end());
          for (int i = 0; i < ans.size(); i++)
               cout << ans[i] << '\n';
     }
     
     return 0;
}