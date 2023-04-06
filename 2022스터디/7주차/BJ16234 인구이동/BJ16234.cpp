#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int solution = 0;

//type 0 빈공간 1 나라 2연합한나라 3닫힌국경 4열린국경
typedef struct node1
{
    int type;
    int people;
}Country;

typedef struct node2
{
    int x;
    int y;
}BFS_NODE;

int n,l,r;
Country arr[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

void bfs(int x, int y)
{
    int sum = arr[x][y].people;    int count = 1;
    queue<BFS_NODE> q;
    q.push({x,y});
    arr[x][y].type = 2;
    // 큐가 빌 때까지 반복
    while (!q.empty())
    {       
        q.pop();
        // 현재 위치에서 상하좌우확인
        for (int i = 0; i < 4; i++)
        {
            int nx = q.front().x + dx[i];
            int ny = q.front().y + dy[i];
            // 공간을 벗어난 경우 무시
            if(nx < 1 || nx >= n+n || ny < 1 || ny >= n+n) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(arr[nx][ny].type == 3 || arr[nx][ny].type == 2 || arr[nx][ny].type == 0) continue;

            // 처음 방문 & 이동 가능
            if (arr[nx][ny].type == 1)
            {
                //방문체크
                arr[nx][ny].type = 2;
                q.push({nx, ny});   
                sum += arr[nx][ny].people;
                count++;
            }
            else if (arr[nx][ny].type == 4)
            {
                arr[nx][ny].type = 3;
                q.push({nx, ny});
                arr[nx][ny].people = 0;
            }
        }
    }
    for (int i = 1; i < n+n; i++)
    {
        for (int j = 0; j < n+n; j++)
        {
            if(arr[i][j].type == 2)
            {
                arr[i][j].people = sum/count;
                arr[i][j].type = 1;
            }
        }   
    }
}

int openBFS()
{
    int end = 0;
    //인구수차이 설정
    for (int i = 2; i < n+n; i+2)
    {
        for (int j = 1; j < n+n; j+2)
        {
            arr[i][j].type = 3;
            arr[i][j].people = max(arr[i-1][j].people,arr[i+1][j].people) - min(arr[i-1][j].people,arr[i+1][j].people);
        }
    }
    for (int i = 1; i < n+n; i+2)
    {
        for (int j = 2; j < n+n; j+2)
        {
            arr[i][j].type = 3;
            arr[i][j].people = max(arr[i][j-1].people,arr[i][j+1].people) - min(arr[i][j-1].people,arr[i][j+1].people);
        }  
    }

    //국경열기
    for (int i = 0; i < n+n; i++)
    {
        for (int j = 0; j < n+n; j++)
        {
            if(arr[i][j].type == 3 && arr[i][j].people >= l && arr[i][j].people <= r)
            {
                end = 1;
                arr[i][j].type = 4;
            }
        }   
    }
    if(end == 0)
    {
        cout << solution << end;
        return 0;
    }


    // 1이랑4로 bfs돌리는데 1이면 sum에 더해주고 2(연합된나라)로 type바꿔줘.
    // 원상복구까지.
    for (int i = 1; i < n+n; i++)
    {
        for (int j = 1; j < n+n; j++)
        {
            if(arr[i][j].type == 1)
            {
                bfs(i,j);
            }
        }  
    }
    
    return 1;
}


int main(void)
{
    cin >> n >> l >> r;

    //Country arr[n+n][n+n] = {{},};

    //초기설정 나라, 닫힌국경, 인구수, 인구수차이 정보입력
    for (int i = 1; i < n+n; i+2)
    {
        for (int j = 1; j < n+n; j+2)
        {
            arr[i][j].type = 1;
            cin >> arr[i][j].people;
        }
    }
    
    while (openBFS() == 1)
    {
        solution++;
        cout << "아";
    }

    
    cout << solution;
    return 0;    
}