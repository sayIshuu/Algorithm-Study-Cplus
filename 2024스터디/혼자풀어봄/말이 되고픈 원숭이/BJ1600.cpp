#include <iostream>
#include <queue>
using namespace std;
//2차원배열에서 [세로,높이][가로,너비] 순서로밖에 생각하게된다
//그래서 입력 똑같이 받고 for문이랑 [y][x]순서로 참조해서 풀어봤다
//그냥 입력부터 그대로 받고 xy 그대로 써도 풀릴거같긴한데..해볼까 안되네..
typedef struct
{
     int x; int y; int depth;
}node;

int k, w, h;
queue<node> q;
int ground[201][201][3];
//[0]입력된맵정보, [1]단순방문체크1이면방문, [2]사용한k횟수

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int kx[8] = {2,2,1,1,-1,-1,-2,-2};
int ky[8] = {1,-1,2,-2,2,-2,1,-1};

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     //===input===
     cin >> k >> w >> h;
     for (int i = 0; i < h; i++)
     {
          for (int j = 0; j < w; j++)
               cin >> ground[i][j][0];
     }
     
     //===bfs first push===
     q.push({0,0,0});
     ground[0][0][1] = 1;
     //===bfs===
     while(!q.empty())
     {
          int x = q.front().x;
          int y = q.front().y;
          int depth = q.front().depth;
          q.pop();
          //===목적지 도착===
          if(x == w-1 && y == h-1)
          {
               cout << depth;
               return 0;
          }
          int nx, ny;
          //===조건하에 말 무빙===
          if(ground[y][x][2] < k)
          {
               for (int i = 0; i < 8; i++)
               {
                    nx = x + kx[i];
                    ny = y + ky[i];
                    //===범위,장애물 체크===
                    if(nx < 0 || nx >= w || ny < 0 || ny >= h)  continue;
                    if(ground[ny][nx][0] == 1) continue;

                    if(ground[ny][nx][1] == 0)
                    {
                         q.push({nx,ny,depth+1});
                         ground[ny][nx][1] = 1;
                         ground[ny][nx][2] = ground[y][x][2]+1;
                         continue;
                    }
                    else if (ground[ny][nx][2] > ground[y][x][2]+1)
                    {
                         q.push({nx,ny,depth+1});
                         ground[ny][nx][2] = ground[y][x][2]+1;
                         continue;
                    }
               }
          }

          //===원숭이 무빙===
          for (int i = 0; i < 4; i++)
          {
               nx = x + dx[i];
               ny = y + dy[i];
               if(nx < 0 || nx >= w || ny < 0 || ny >= h)  continue;
               if(ground[ny][nx][0] == 1) continue;

               if(ground[ny][nx][1] == 0)
               {
                    q.push({nx,ny,depth+1});
                    ground[ny][nx][1] = 1;
                    ground[ny][nx][2] = ground[y][x][2];
                    continue;
               }
               else if (ground[ny][nx][2] > ground[y][x][2])
               {
                    q.push({nx,ny,depth+1});
                    ground[ny][nx][2] = ground[y][x][2];
                    continue;
               }
          }
     }

     cout << -1;
     return 0;
}