#include <iostream>
#include <queue>
using namespace std;

int n,m,k;
typedef struct 
{
     int x,y,depth,kcnt;
}node;
char map[1002][1002][2];
int kcntMap[1002][1002];
//[0]=벽여부, [1]=방문체크, kcntMap=k사용횟수

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int _x, int _y)
{
     map[_x][_y][1] = '1';
     queue<node> q;
     q.push({_x,_y,1,0});

     while (!q.empty())
     {
          int x = q.front().x;
          int y = q.front().y;
          int depth = q.front().depth;
          int kcnt = q.front().kcnt;
          q.pop();

          for (int i = 0; i < 4; i++)
          {
               int nx = x + dx[i];
               int ny = y + dy[i];

               if(nx == n-1 && ny == m-1)
               {
                    cout << depth+1;
                    return;
               }

               if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

               if(map[nx][ny][1] == '1')
               {
                    //push할 노드가 통로인데, k를 더쓰고 방문했었을 때
                    if(map[nx][ny][0] == '0' && kcntMap[nx][ny] > kcnt)
                    {
                         q.push({nx,ny,depth+1,kcnt});
                         kcntMap[nx][ny] = kcnt;
                         continue;
                    }

                    if (map[nx][ny][0] == '1' && kcntMap[nx][ny] > kcnt+1)
                    {
                         q.push({nx,ny,depth+1,kcnt+1});
                         kcntMap[nx][ny] = kcnt+1;
                         continue;
                    }
               }
               else if(map[nx][ny][1] == '0')
               {
                    if(map[nx][ny][0] == '0')
                    {
                         map[nx][ny][1] = '1'; //방문체크
                         kcntMap[nx][ny] = kcnt;
                         q.push({nx,ny,depth+1,kcnt});
                         continue;
                    }
                    
                    if(map[nx][ny][0] == '1')//벽일경우
                    {
                         if(kcnt >= k) continue;

                         map[nx][ny][1] = '1';
                         kcntMap[nx][ny] = kcnt+1;
                         q.push({nx,ny,depth+1,kcnt+1});
                         continue;
                    }
               }
          }
          
     }
     cout << -1;
}


int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m >> k;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < m; j++)
          {
               cin >> map[i][j][0];
               map[i][j][1] = '0';
          }
     }
     if(n==1 && m==1)
     {
          cout << 1;
          return 0;
     }
     

     bfs(0,0);
     

     return 0;
}