#include <iostream>
#include <queue>
using namespace std;
//2�����迭���� [����,����][����,�ʺ�] �����ιۿ� �����ϰԵȴ�
//�׷��� �Է� �Ȱ��� �ް� for���̶� [y][x]������ �����ؼ� Ǯ��ô�
//�׳� �Էº��� �״�� �ް� xy �״�� �ᵵ Ǯ���Ű����ѵ�..�غ��� �ȵǳ�..
typedef struct
{
     int x; int y; int depth;
}node;

int k, w, h;
queue<node> q;
int ground[201][201][3];
//[0]�Էµȸ�����, [1]�ܼ��湮üũ1�̸�湮, [2]�����kȽ��

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
          //===������ ����===
          if(x == w-1 && y == h-1)
          {
               cout << depth;
               return 0;
          }
          int nx, ny;
          //===�����Ͽ� �� ����===
          if(ground[y][x][2] < k)
          {
               for (int i = 0; i < 8; i++)
               {
                    nx = x + kx[i];
                    ny = y + ky[i];
                    //===����,��ֹ� üũ===
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

          //===������ ����===
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