#include <iostream>
#include <queue>
#include <string>
using namespace std;

char field[13][6];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

typedef struct
{
    int x;  int y;
}s;

int ans = 0; //연쇄횟수

void input()
{
    //내려주기 할때 맨위칸이 내려가면 점으로 바뀌니까 내려주는 개념그대로사용하기위해 0번째 줄은 .으로 설정
    for (int i = 0; i < 6; i++)
        field[0][i] = '.';
    
    for (int i = 1; i < 13; i++)
            cin >> field[i];
}

bool didYouPuyo;
void bfs(int _x, int _y, char puyo)
{
    bool check[13][6] = {}; //<=지역변수는 디폴트선언해주자.. 안그러면 쓰레기값
    queue<s> q;
    q.push({_x,_y}); int cnt = 1; //4개넘으면 puyo해줘야하니까
    check[_x][_y] = true;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx >= 13 || ny < 0 || ny >= 6) continue;

            if (check[nx][ny]) continue;

            if (field[nx][ny] == puyo)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    if(cnt > 3)
    {
        for (int i = 1; i < 13; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if(check[i][j])
                    field[i][j] = '.';
            }
        }
        didYouPuyo = true;
    }
}


void downPuyo() // 빈자리 내려주는 함수
{
    for (int i = 1; i < 12; i++) //맨 밑칸은 상관없으니 < 12
    {
        for (int j = 0; j < 6; j++)
        {
            if(field[i][j] != '.' && field[i+1][j] == '.')
            {
                for (int t = i+1; t > 0; t--)
                    field[t][j] = field[t-1][j];
            }
        }
    }
}

void traversal() //한바퀴 순회하며 터트린다 터트렸으면 연쇄+1
{
    didYouPuyo = false;
    for (int i = 1; i < 13; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if(field[i][j] != '.')
                bfs(i,j,field[i][j]);
        }
    }
    if(didYouPuyo)
    {
        ans++;
        downPuyo();
        traversal();
    }
    else{
        cout << ans;
        return;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    traversal();
    return 0;
}