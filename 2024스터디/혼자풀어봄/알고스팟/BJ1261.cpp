#include <iostream>
#include <deque>
using namespace std;

//�ִܰ�ΰ� ������� �ʾƵ� �ȴ�.
//�߿��� �� ���� �ּ������� �μ��� ��.
//���� ���� �����ִ� ��� �� �߿� �ϳ��� ����� �ִٸ� �ű⸦ �켱���� Ž���Ѵ�.
//�Ź� �����ִ� �� �� ����� ã�Ƴ��� �켱����ť�� �ϳ��� ���������,
//deque�� ����� ����� front��, ���� back���� push���ָ�ȴ�.
//��波��, �������� �켱������ ����. �ƹ�ư �������ϸ�ȴ�.
//�ƴϴ�. �ִ�. ���� ���߿����� ���������ϴ� �ְ� �ּҷ� �μ��ִ�.

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
     //n�� �̷��� ����, m�� �̷��� ���θ� ��Ÿ����.
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