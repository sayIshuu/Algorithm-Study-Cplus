#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
배열 쭉도는 큰반복문.
count변수
1걸린다? 너비우선탐색 => 개수세고, 0으로 방문체크해줘
끝
*/
int n;  //헤더파일과 같은 원리로,, 선언은 먼저해놓아야 함수에서 활용가능.

typedef struct node
{
    int x;
    int y;
}Node;

int map[25][25];

//size는 총 단지수, 값은 각 단지의 집의 수 마지막에 오름차순 정렬하면 됨.
vector<int> num;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};



//상하좌우, 방문체크 해서 큐에 푸쉬하는 함수
void bfs(int tx, int ty) // 인자는 처음 들어가는 값
{
    int count = 1;
    map[tx][ty] = 0;
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
            if(nx < 0 || nx > n || ny < 0 || ny > n) continue;

            // 이동할 수 없는 칸인 경우 무시
            if(map[nx][ny] == 0) continue;

            // 처음 방문 & 이동 가능
            if (map[nx][ny] == 1)
            {
                //방문체크
                map[nx][ny] = 0;
                q.push({nx, ny});
                count++;
            }
        }
    }
    //일단 방금 뽑은 단지의 집 수 추가. 정렬은 나중에
    num.push_back(count);
}


int main(void)
{
    //맵 구성
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            map[i][j] = temp[j]-'0';
        }
    }


    //한칸씩 돌면서 1인 칸 찾기, 찾으면 bfs함수돌려서 단지 하나뽑고, 다 0으로 만들기
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(map[i][j] == 0) continue;
            //너비우선탐색 & 방문체크
            if(map[i][j] == 1)
            {
                bfs(i,j);
            }
        }   
    }
    
    //vector의 오름차순 정렬 by sort함수
    sort(num.begin(),num.end());
    cout << num.size() << endl;
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}