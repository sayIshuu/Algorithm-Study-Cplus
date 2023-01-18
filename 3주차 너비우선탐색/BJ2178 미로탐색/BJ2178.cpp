//BJ2178 미로탐색 실1 알고리즘멘토링 3주차 너비우선탐색
#include <iostream>
#include <string>
#include <queue>
using namespace std;

//문제아이디어 : 어차피 너비우선탐색은 최단거리를 구해낸다. 계층구조로 접근

int n,m;
int miro[100][100]; //인덱스접근 -1 주의

//큐의 요소가 될 구조체
typedef struct node
{
    int x;
    int y;
    int level;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

//상하좌우, 방문체크 해서 큐에 푸쉬하는 함수
void bfs()
{
    miro[0][0] = 0;
    queue<Node> q;
    q.push({0, 0, 1});
    // 큐가 빌 때까지 반복
    while (!q.empty())
    {
        //목적지 도착하면 목적지 레벨 출력하고 끝
        if(q.back().x == n-1 && q.back().y == m-1)
        {
            cout << q.back().level << endl;
            break;
        }
        int x = q.front().x;
        int y = q.front().y;
        int level = q.front().level;
        q.pop();
        // 현재 위치에서 상하좌우확인
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 미로 공간을 벗어난 경우 무시
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(miro[nx][ny] == 0) continue;

            // 처음 방문 & 이동 가능
            if (miro[nx][ny] == 1)
            {
                //방문체크
                miro[nx][ny] = 0;
                q.push({nx, ny, level+1});
            }
        }
    }
}




int main(void)
{
    // 2차원배열로 미로 구성
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        //자릿수별로 몫,나머지 구하기보단 문자열로 받고 한글자씩 형변환
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            miro[i][j] = temp[j]-'0';
        }
    }

    //너비우선탐색으로 최단거리 도출
    //큐가 미로의 위치정보를 가지고 있어야함 => 구조체
    bfs();
    
    return 0;
}



/*
//큐가 미로의 위치정보를 가지고 있어야함 => 구조체
    queue<Node> q;
    //기준이 될 맨앞칸 푸쉬 후 방문체크, 계층은 1부터 시작.
    q.push({0,0,1});
    miro[0][0] = 0;
    
    while (!q.empty())
    {
        Node front = q.front();
        int x = front.N;
        int y = front.M;
        //목적지 도착하면 목적지 레벨 출력하고 끝
        if(q.back().N == n-1 && q.back().M == m-1)
        {
            cout << q.back().level << endl;
            break;
        }

        //상하좌우 범위, 방문체크해서 push와 동시에 방문체크까지.
        //우
        if(x+1 >= 0 && x+1 < n)
        {
            if(miro[x+1][y] == 1)
            {
                q.push({x+1,y,front.level+1});
                miro[x+1][y] = 0;
            }
        }
        //하
        if(y+1 >= 0 && y+1 < m)
        {
            if(miro[x][y+1] == 1)
            {
                q.push({x,y+1,front.level+1});
                miro[x][y+1] = 0;
            }
        }
        //좌
        if(x-1 >= 0 && x-1 < n)
        {
            if(miro[x-1][y] == 1)
            {
                q.push({x-1,y,front.level+1});
                miro[x-1][y] = 0;
            }
        }
        //상
        if(y-1 >= 0 && y-1 < m)
        {
            if(miro[x][y-1] == 1)
            {
                q.push({x,y-1,front.level+1});
                miro[x][y-1] = 0;
            }
        }

        //맨앞노드 팝
        q.pop(); 
    }
    */