#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
    int x,y,z;
    int level;
}node;

int m,n,h,ans;

int map[101][101][101];

int dx[] = {0,0,1,-1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};

int main(void)
{
    cin >> m >> n >> h;

    queue<node> q;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[i][j][k];
                if(map[i][j][k]==1)
                    q.push({i,j,k,0});
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        int l = q.front().level;
        ans = max(ans,l);
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && nz>=0 && nz<h)
            {
                if(map[nx][ny][nz] == -1)
                    continue;
                else if(map[nx][ny][nz]==0)
                {
                    map[nx][ny][nz] = 1;
                    q.push({nx,ny,nz,l+1});
                }
            }
        }
    }
    

    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j][k]==0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << ans;
    return 0;
}