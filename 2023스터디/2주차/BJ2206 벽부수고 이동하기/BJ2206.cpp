//핵심은 3차원 배열
//부순상태인지 아닌지도 저장하면 된다. 5:36~
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n,m;
char map[1002][1002][2];
//푸쉬할때 체크할 조건은 구조체가 아니라 map에 저장해놔야 한다 그래서 3차원배열
typedef struct
{
    int x;
    int y;
    int depth;
}node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int tx, int ty) // 인자는 처음 들어가는 값
{
    map[tx][ty][1] = 'T';
    queue<node> q;
    q.push({tx, ty, 1});
    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int depth = q.front().depth;
        q.pop();
        // 현재 위치에서 상하좌우확인
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //도착지 도착하면 끝내버렷 어차피 벽아닌게 확실하니 여기써도 돼
            if(nx == n-1 && ny == m-1)
            {
                cout << depth+1;
                return;
            }

            // 미로 공간을 벗어난 경우 무시
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(map[x][y][1] == 'T')
            {
                if(map[nx][ny][0] == '0')
                {
                    //방문체크
                    if(map[nx][ny][1] == 'T')   continue;

                    map[nx][ny][1] = 'T';
                    q.push({nx,ny,depth+1});
                    continue;
                }
                else if(map[nx][ny][0] == '1')
                {
                    //방문체크
                    if(map[nx][ny][1] == 'F')   continue;

                    map[nx][ny][1] = 'F';
                    q.push({nx,ny,depth+1});
                    continue;
                }
            }
            else if(map[x][y][1] == 'F')
            {
                if(map[nx][ny][0] == '0')
                {
                    //방문체크
                    if(map[nx][ny][1] == 'T' || map[nx][ny][1] == 'F')  continue;

                    map[nx][ny][1] = 'F';
                    q.push({nx,ny,depth+1});
                }
                else if(map[nx][ny][0] == '1')
                    continue;
            }
        }
    }
    cout << -1;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j][0];
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