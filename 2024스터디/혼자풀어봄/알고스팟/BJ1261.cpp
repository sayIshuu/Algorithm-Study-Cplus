#include <iostream>
#include <deque>
using namespace std;

//최단경로가 보장되지 않아도 된다.
//중요한 건 벽을 최소한으로 부수는 것.
//따라서 현재 접해있는 모든 면 중에 하나라도 빈방이 있다면 거기를 우선으로 탐색한다.
//매번 접해있는 방 중 빈방을 찾아내는 우선순위큐도 하나의 방법이지만,
//deque를 사용해 빈방은 front로, 벽은 back으로 push해주면된다.
//빈방끼리, 벽끼리는 우선순위가 없다. 아무튼 도착만하면된다.
//아니다. 있다. ㅋㅋ 그중에서도 먼저도착하는 애가 최소로 부순애다.

int n,m,ans;

typedef struct
{
     int x,y,broken;
}node;
deque<node> dq;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

char miro[101][101];
bool visited[101][101];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     //n이 미로의 가로, m이 미로의 세로를 나타낸다.
     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
               cin >> miro[i][j];
     }

     dq.push_front({0,0,0});
     visited[0][0] = true;

     while (!dq.empty())
     {
          int x = dq.front().x;
          int y = dq.front().y;
          int broken = dq.front().broken;
          dq.pop_front();

          if(miro[x][y] == '1') broken++;
          if(x==m-1 && y==n-1){
               ans = broken;
               break;
          }

          for (int i = 0; i < 4; i++)
          {
               int nx = x+dx[i];
               int ny = y+dy[i];

               if(nx > m-1 || nx < 0 || ny > n-1 || ny < 0) continue;
               if(visited[nx][ny]) continue;

               if(miro[nx][ny] == '0') dq.push_front({nx,ny,broken});
               else if(miro[nx][ny] == '1') dq.push_back({nx,ny,broken});
               visited[nx][ny] = true;
          }
     }
     
     cout << ans;

     return 0;
}