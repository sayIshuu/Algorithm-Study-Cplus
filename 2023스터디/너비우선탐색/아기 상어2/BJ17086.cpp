#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int arr[51][51];

typedef struct
{
     int x,y;
     int depth;
}node;

queue<node> q;

void input()
{
     cin >> n >> m;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++){
               cin >> arr[i][j];
               if(arr[i][j] == 1)
                    q.push({i,j,0});
          }
     }
}

int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

void solution()
{
     while (!q.empty())
     {
          int x = q.front().x;
          int y = q.front().y;
          int depth = q.front().depth;
          q.pop();
          for (int i = 0; i < 8; i++)
          {
               int nx = x+dx[i];
               int ny = y+dy[i];

               if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
               
               if(arr[nx][ny] == 0 || arr[nx][ny] > depth+1)
               {
                    arr[nx][ny] = depth+1;
                    q.push({nx,ny,depth+1});
               }
          }
     }
}

void solve()
{
    input();
    solution();

     int ans = 0;
    for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
              ans = max(ans,arr[i][j]);
          }
     }
     cout << ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}