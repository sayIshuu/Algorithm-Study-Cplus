#include <iostream>
#include <queue>
using namespace std;

int arr[101][2];   //인덱스는 칸번호,
//[x][0]값은 방문체크용 도착했을 때 깊이, [x][1]값은 연결된 인덱스(뱀이나 사다리가 아니라면 자기 자신의 인덱스)

void BFS()  //상하좌우가 아니라 654321순서로 탐색
{
    queue<int> q; //q에 들어가는건 맵 인덱스
    arr[1][0] = 0;
    q.push(1);

    while (!q.empty())
    {
        int x = q.front();
        int step = arr[x][0];
        q.pop();

        for (int i = 6; i >= 0; i--)
        {
            //인덱스범위
            if(x+i > 100)   continue;

            //도착하면 출력
            if(x+i == 100)
            {
                cout << step+1;
                return;
            }

            //가려고 하는곳을 먼저 갔었다?
            //if(arr[x+i][0] < step+1)   continue;

            //뱀or사다리일 경우 연결된 곳을 먼저 갔었다?
            if(arr[arr[x+i][1]][0] != 0 && arr[arr[x+i][1]][0] < step+1)   continue;

            //방문체크 후 푸쉬
            arr[arr[x+i][1]][0] = step+1;
            q.push(arr[x+i][1]);
        }
        
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 101; i++)
    {
        arr[i][1] = i;
    }
    
    int n,m; cin >> n >> m;
    for (int i = 0; i < n+m; i++)
    {
        int a,b;    cin >> a >> b;
        arr[a][1] = b;
    }
    
    BFS();

    return 0;
}