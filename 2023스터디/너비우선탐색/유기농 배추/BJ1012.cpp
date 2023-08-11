#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, n, m, num;
int map[50][50];

typedef struct
{
    int x;  int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int tx, int ty)
{
    map[tx][ty] = 0;    //방문체크
    queue<Node> q;
    q.push({tx, ty});
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (map[nx][ny] == 1)
            {
                map[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--)
    {
        cin >> m >> n >> num;

        while (num--)
        {
            int x,y;
            cin >> y >> x;
            map[x][y] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j] == 1)
                {
                    bfs(i,j);
                    cnt++;
                }
            }   
        }

        cout << cnt << '\n';
    }

    return 0;
}