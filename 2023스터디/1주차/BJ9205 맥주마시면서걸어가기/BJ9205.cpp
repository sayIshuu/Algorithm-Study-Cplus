#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//입력값의 범위가 곧 문제풀이의 힌트
//x,y범위 = 30*30 =900인데 128메가니까 맵을 직접만들게 아님
//장애물이 없으니까 맨해튼거리로 푸쉬하는걸 생각
//편의점 개수도 100개, 좀 비효율적이여도 돼
//반복문돌때마다 편의점 다 확인

typedef struct{ //큐에 들어갈 애
    int x,y;
    //int lastBeer;
    //int lastMeter;
}node;

int t;
int n;
node home;
node fesitval;
node convini[100];
bool visited[100];

void bfs()
{   
    queue<node> q;
    q.push(home);
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(abs(x-fesitval.x)+abs(y-fesitval.y) <= 1000)
        {
            cout << "happy" << '\n';
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            
            if(abs(x-convini[i].x)+abs(y-convini[i].y) <= 1000)
            {
                visited[i] = true;
                q.push(convini[i]);
            }
        }
    }
    cout << "sad" << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> home.x >> home.y;
        for (int i = 0; i < n; i++)
        {
            cin >> convini[i].x >> convini[i].y;
        }
        cin >> fesitval.x >> fesitval.y;

        bfs();

        
        for (int i = 0; i < 100; i++)
        {
            convini[i] = {0,0};
            visited[i] = false;
        }
    }
    
    

    return 0;
}