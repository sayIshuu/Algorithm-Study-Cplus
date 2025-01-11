#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int answer;
int n,m;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct
{
    int x,y;
    int depth;
}node;

string map[52];

bool visited[52][52];
void clearVisited()
{
    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            visited[i][j] = false;
}

queue<node> q;

bool isStartPoint(int x, int y)
{
    if(map[x][y] != 'L')
        return false;
    if((map[x+1][y] == 'L' && map[x-1][y] == 'L')
        || (map[x][y+1] == 'L' && map[x][y-1] == 'L'))
        return false;
    else
        return true;
}

void bfs(int i, int j)
{
    q.push({i,j,0});
    visited[i][j] = true;

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int depth = q.front().depth;
        answer = max(depth,answer);
        q.pop();

        for (int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(map[nx][ny] == 'L' && !visited[nx][ny]){
                q.push({nx,ny,depth+1});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    string tmp = "";
    for (int i = 1; i <= n; i++){
        map[i] = " ";
        cin >> tmp;
        map[i] += tmp += " ";
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(isStartPoint(i,j)){
                q = queue<node>();
                clearVisited();
                bfs(i,j);
            }
        }
    }
    
    cout << answer;

    return 0;
}