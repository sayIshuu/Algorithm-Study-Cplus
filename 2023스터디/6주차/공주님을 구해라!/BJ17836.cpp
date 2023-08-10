#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n,m,t;
int miro[101][101];

typedef struct
{
    int x;
    int y;
    int time;
    bool gram;  // pop하는 front의 노드로 확인하려면 구조체 안변수로 통제
}node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

//bool gram = false; push할때 확인하려면 구조체 밖변수로 통제

void bfs()
{
    miro[0][0] = 3; //방문체크 = 3
    queue<node> q;
    q.push({0, 0, 0, false});
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        bool gram = q.front().gram;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx == n-1 && ny == m-1 && time < t)
            {
                cout << time+1;
                return;
            }

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(gram)
            {
                if(i==1 || i ==2 && miro[nx][ny] != 4)
                {
                    q.push({nx,ny,time+1,gram});
                    miro[nx][ny] = 4;
                }
            }
            else{
                if(miro[nx][ny] == 2)
                {
                    q.push({nx,ny,time+1,true});
                }
                else if(miro[nx][ny] == 0)
                {
                    q.push({nx,ny,time+1,gram});
                    miro[nx][ny] = 3;
                }
            }
        }
    }
    cout << "Fail";
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> miro[i][j];
    }
    bfs();
    
    return 0;
}