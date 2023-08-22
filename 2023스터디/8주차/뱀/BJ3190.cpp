#include <iostream>
#include <deque>
using namespace std;

typedef struct
{
    int x; int y;
}node;

int n,k,l;
int time;

bool apple[101][101] = {0,};
bool isFill[101][101] = {0,};

deque<node> snake;

pair<int,int> info[10001];

void input()
{
    cin >> n >> k;

    while (k--)
    {
        int i,j;
        cin >> i >> j;
        apple[i][j] = true;
    }

    cin >> l;
    while (l--)
    {
        int s;  char c;
        cin >> s >> c;

        if(c == 'L')    // 실수 c='L'
            info[s] = {1,-1};
        else if(c == 'D')
            info[s] = {1,1};
    }

    snake.push_front({1,1}); // 인덱스 0은 안쓴다
    isFill[1][1] = true;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int idex = 100;
int dir = idex%4; // dir = 0

void solve()
{
    while(true)
    {
        if(info[time].first == 1)
        {
            idex += info[time].second;
            dir = idex%4;
        }

        int x = snake.front().x;
        int y = snake.front().y;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx <= 0 || ny <= 0 || nx > n || ny > n || isFill[nx][ny]){
            cout << time+1;
            return;
        }

        if(apple[nx][ny]){
            snake.push_front({nx,ny});
            isFill[nx][ny] = true;
            apple[nx][ny] = false;
        }
        else{
            snake.push_front({nx,ny});
            isFill[nx][ny] = true;
            isFill[snake.back().x][snake.back().y] = false;
            snake.pop_back();
        }

        time++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    solve();

    return 0;
}