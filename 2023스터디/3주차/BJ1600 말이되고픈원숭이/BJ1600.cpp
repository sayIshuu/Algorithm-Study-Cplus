#include <iostream>
#include <queue>
using namespace std;
//실패!!
int map[200][200][2]; //갔을 때 남은 k를 저장해서 k가 더많은상태면 방문체크 미적용
int k,w,h;
typedef struct //갔었던 곳의 정보를 저장할 뿐, 갈때 확인할 정보는 아님
{
  int x;
  int y;
  int rest_k;
  int depth;
}node;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int kx[8] = {2,2,1,1,-1,-1,-2,-2};
int ky[8] = {1,-1,2,-2,2,-2,1,-1};


void BFS()
{
  queue<node> q;
  map[0][0][0] = 2; //방문체크. 갔던곳
  map[0][0][1] = 0; //k를 쓴 횟수
  q.push({0,0,k,0});

  while (!q.empty())
  {
    int x = q.front().x;
    int y = q.front().y;
    int rk = q.front().rest_k;
    int d = q.front().depth;
    q.pop();

    for (int i = 0; i < 8; i++)
    {
      int nx = x+kx[i];
      int ny = y+ky[i];

      if(nx < 0 || nx >= w || ny < 0 || ny >= h)  continue;
      if(map[ny][nx][0] == 1) continue;
      if(rk == 0) continue;
      if(map[ny][nx][0] == 2)//  continue; //말로도 갔던곳 또 갈 가능성이 있나 의문
      {
        if(map[ny][nx][1] > map[y][x][1])
        {
          map[ny][nx][1] = map[y][x][1]+1;
          q.push({nx,ny,rk-1,d+1});
          continue;
        }
      }

      if(nx == w-1 && ny == h-1)
      {
        cout << d+1;
        return;
      }

      map[ny][nx][0] = 2;
      map[ny][nx][1]++;
      q.push({nx,ny,rk-1,d+1});
    }
    
    for (int i = 0; i < 4; i++)
    {
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(nx < 0 || nx >= w || ny < 0 || ny >= h)  continue;
      if(map[ny][nx][0] == 1) continue;

      if(map[ny][nx][0] == 0)
      {
        if(nx == w-1 && ny == h-1)
        { 
          cout << d+1;
          return;
        }
        map[ny][nx][0] = 2;
        map[ny][nx][1] = map[y][x][1];
        q.push({nx,ny,rk,d+1});
        continue;
      }

      if(map[ny][nx][0] == 2)
      {
        if(map[ny][nx][1] > map[y][x][1])
        {
          map[ny][nx][1] = map[y][x][1];
          q.push({nx,ny,rk,d+1});
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

  cin >> k;
  cin >> w >> h; 

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> map[i][j][0];
    }
  }
  
  BFS();

  return 0;
}