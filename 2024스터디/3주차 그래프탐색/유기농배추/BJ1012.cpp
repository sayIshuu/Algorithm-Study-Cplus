#include <iostream>
#include <queue>
using namespace std;

int t;
int x,y,num;
int a,b;
int qkx[51][51];


typedef struct
{
    int x;  int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int tx, int ty)
{
     qkx[tx][ty] = 0;    //방문체크
     queue<Node> q;
     q.push({tx, ty});
     while (!q.empty())
     {
          int px = q.front().x;
          int py = q.front().y;
          q.pop();
          for (int i = 0; i < 4; i++)
          {
               int nx = px + dx[i];
               int ny = py + dy[i];
               if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;

               if (qkx[nx][ny] == 1)
               {
                    qkx[nx][ny] = 0;
                    q.push({nx, ny});
               }
          }
     }
}


int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> t;
     for (int i = 0; i < t; i++)
     {
          int cnt = 0;
          cin >> x >> y >> num;

          for (int j = 0; j < num; j++)
          {
               cin >> a >> b;
               qkx[a][b] = 1;
          }
          
          for (int q = 0; q < x; q++)
          {
               for (int w = 0; w < y; w++)
               {
                    if(qkx[q][w] == 1)
                    {
                         bfs(q,w);
                         cnt++;
                    }
               }
          }
          cout << cnt << '\n';
     }
     

     return 0;
}