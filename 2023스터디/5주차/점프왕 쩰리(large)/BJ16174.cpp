#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef struct
{
    int x; int y;
}s;
int n; 
int map[101][101];
bool visited[101][101];
queue<s> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }
    
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(map[x][y]==-1)
        {
            cout << "HaruHaru";
            return 0;
        }

        int nx = x+map[x][y];
        if(nx < n && !visited[nx][y])
        {
            visited[nx][y] = true;
            q.push({nx,y});
        }
        int ny = y+map[x][y];
        if(ny < n && !visited[x][ny])
        {
            visited[x][ny] = true;
            q.push({x,ny});
        }
    }

    cout << "Hing";
    return 0;
}