#include <iostream>
#include <deque>
using namespace std;

typedef struct
{
    int x; int y;
}node;

int n,k,l;
int time = 1;

bool apple[101][101] = {0,};
bool isFill[101][101] = {0,};

deque<node> snake;

deque<pair<int,int>> info;

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

        if(c == 'L')
            info.push_back({s,-1});
        else if(c == 'D')
            info.push_back({s,1});
    }

    snake.push_front({1,1}); // 인덱스 0은 안쓴다
    isFill[1][1] = true;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int idex = 100;
int dir = idex%4; // dir = 0

void progress(pair<int,int> _info)
{
    int t = _info.first;
    idex += _info.second;
    dir = idex%4;
    //cout << idex << dir << endl;
    while(t--)
    {
        int x = snake.front().x;
        int y = snake.front().y;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        cout << x << y << nx << ny << endl;
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || isFill[nx][ny]){
            info.clear();
            cout << time;
            return;
        }

        if(apple[nx][ny]){
            
            snake.push_front({nx,ny});
            isFill[nx][ny] = true;
            apple[nx][ny] = false;
            time++;
            continue;
        }
        else{
            //cout << "여기가 한번은 들어가야지";
            snake.push_front({nx,ny});
            isFill[nx][ny] = true;
            time++;
            isFill[snake.back().x][snake.back().y] = false;
            snake.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    for (int i = 0; i < info.size(); i++)
    {
        cout << "------" << endl;
        progress(info[i]);
    }

    return 0;
}