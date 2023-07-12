#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
char map[100][100];
char map_copy[100][100];

typedef struct
{
    int x;
    int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

//상하좌우, 방문체크 해서 큐에 푸쉬하는 함수
void bfs(int tx, int ty, char data) // 인자는 처음 들어가는 값
{
    map[tx][ty] = 'N';
    queue<Node> q;
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(map[nx][ny] != data) continue;

            // 처음 방문 & 이동 가능
            if (map[nx][ny] == data)
            {
                //방문체크
                map[nx][ny] = 'N';
                q.push({nx, ny});
            }
        }
    }
}



//상하좌우, 방문체크 해서 큐에 푸쉬하는 함수
void bfs_copy(int tx, int ty, char data) // 인자는 처음 들어가는 값
{
    map[tx][ty] = 'N';
    queue<Node> q;
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(map_copy[nx][ny] != data) continue;

            // 처음 방문 & 이동 가능
            if (map_copy[nx][ny] == data)
            {
                //방문체크
                map_copy[nx][ny] = 'N';
                q.push({nx, ny});
            }
        }
    }
}




int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j];
            if(temp[j] == 'G')
            {
                temp[j] = 'R';
            }
            map_copy[i][j] = temp[j];
        }
    }  


    int count_1 = 0;
    //한칸씩 돌면서 너비우선탐색 돌면(N이 아니면)count++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j] == 'N') continue;
            //너비우선탐색 & 방문체크
            if(map[i][j] != 'N')
            {
                bfs(i,j,map[i][j]);
                count_1++;
            }
        }   
    }


    int count_2 = 0;
    //한칸씩 돌면서 너비우선탐색 돌면(N이 아니면)count++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map_copy[i][j] == 'N') continue;
            //너비우선탐색 & 방문체크
            if(map_copy[i][j] != 'N')
            {
                bfs_copy(i,j,map_copy[i][j]);
                count_2++;
            }
        }   
    }


    cout << count_1 << ' ' << count_2;
    return 0;
}






// 단지번호붙이기 응용. 배열의 재사용이 가능하면 두번칠거 한번칠듯. 나중에..

//memset활용하여 초기화하는 단계를 따로 두어서 재활용하면 하나의 map으로 풀 수 있을거 같아요
//추가로 문자열 입력받을 때 cin이 띄워쓰기 없어도 나누어 받아줌