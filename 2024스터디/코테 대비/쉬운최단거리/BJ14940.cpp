#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[1001][1001];
bool visited[1001][1001];

typedef struct
{
     int x,y;
}node;

queue<node> q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     for (int i = 0; i < n; i++)
          for (int ii = 0; ii < m; ii++){
               cin >> arr[i][ii];
               if(arr[i][ii] == 2){
                    q.push({i,ii});
                    arr[i][ii] = 0;
                    visited[i][ii] = true;
               }
          }

     while(!q.empty())
     {
          int x = q.front().x;
          int y = q.front().y;
          q.pop();

          for (int i = 0; i < 4; i++)
          {
               int nx = x+dx[i];
               int ny = y+dy[i];

               if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
               if(visited[nx][ny] || arr[nx][ny] == 0) continue;

               q.push({nx,ny});
               visited[nx][ny] = true;
               arr[nx][ny] = arr[x][y]+1;
          }
     }

     for (int i = 0; i < n; i++)
     {
          for (int ii = 0; ii < m; ii++)
          {
               if (!visited[i][ii] && arr[i][ii] != 0)
               {
                    arr[i][ii] = -1;
               }
               cout << arr[i][ii] << ' ';
          }
          cout << '\n';
     }
     return 0;
}