#include <iostream>
#include <queue>
using namespace std;

//문제아이디어 :
//초기 설정 0 : 빈공간, 1: 치즈..... 현재개수 count 저장
//바깥 빈공간 -> 5
//c 찾기 : 3 (BFS)
//c 녹이기, hour++
//2 -> 0으로 초기화.
//반복.
//현재개수 0이면 hour랑 이전 count 출력.

int n,m;
int map[101][101] = {};

int hour = 0;
int count = 0;

typedef struct node
{
    int x;
    int y;
}NODE;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

//바깥 빈공간 => 5, c찾기 => 3
void bfs(int tx, int ty) // 인자는 처음 들어가는 값
{
    map[tx][ty] = 5;
    queue<NODE> q;
    q.push({tx, ty});
    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        // 현재 위치에서 상하좌우확인
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 미로 공간을 벗어난 경우 무시
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if(map[nx][ny] == 5) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(map[nx][ny] == 1)
            {
                map[nx][ny] = 3;
                continue;
            }

            // 처음 방문 & 이동 가능
            if (map[nx][ny] == 0)
            {
                //방문체크
                map[nx][ny] = 5;
                q.push({nx, ny});
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;
//초기세팅
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
                count++;
        }   
    }
    if(count == 0)
    {
        cout << hour << '\n';
        cout << count;
        return 0;
    }
    while(true)
    {
//바깥 빈공간 => 5, c찾기 => 3
        bfs(0,0);   
//hour++   c지우기, 초기화
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j] == 5 || map[i][j] == 3)
                    map[i][j] = 0;
            }       
        }
        hour++;
//현재 개수
        int temp_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(map[i][j] == 1)
                    temp_count++;
            }   
        }   
        if(temp_count == 0)
        {
            cout << hour << '\n';
            cout << count;
            return 0;
        }
        count = temp_count;
    }

    return 0;
}