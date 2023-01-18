//BJ7576 토마토 골5 너비우선탐색 언타멘토링 3주차
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/*
    map작성
    구조체활용한 큐.. x,y,time

    먼저 map을 한바퀴 돌며 1위치 다 찾아낸다.
    각각의 1 위치를 시작점으로한 큐를 vector<queue<Node>> list;로 받는다.
    반복문에서 큐의 인덱스를 돌리고
     반복문코드에서 bfs()한바퀴씩만 돌림.
     bfs()가 안돌때 time이 답.
    답내기전에 map한번 쫙돌고 0있으면 -1출력
*/


int n,m;

typedef struct node
{
    int x;
    int y;
}Node;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};



int main(void)
{
    cin >> m >> n; // 문제가 좀 이상하다 그림이랑 예제랑 90도 다름.
    int map[n][m];
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==0) zero++;
        }  
    }
    if(zero==0)
    {
        cout << 0;
        return 0;
    }
    


    //1찾으면 큐형으로 벡터에 넣기
    vector<queue<Node>> list;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                queue<Node> temp;
                temp.push({i,j});
                list.push_back(temp);
            }
        }   
    }


    int time = 0;
    while(true)
    {
        int temp = 0;
        for (int j = 0; j < list.size(); j++)
        {
            int k = list[j].size();
            while(k--)
            {
                // list[j]로 bfs한바퀴씩.
                int x = list[j].front().x;
                int y = list[j].front().y;
                list[j].pop();
                // 현재 위치에서 상하좌우확인
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    // 미로 공간을 벗어난 경우 무시
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                    // 이동할 수 없는 칸인 경우 무시
                    if(map[nx][ny] != 0) continue;

                    // 처음 방문 & 이동 가능
                    if (map[nx][ny] == 0)
                    {
                        //방문체크
                        map[nx][ny] = 1;
                        list[j].push({nx,ny});
                        temp++;
                    }
                }
            }
        }
        if(temp == 0) break;
        time++;
    } 
    


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }  
    }   

    cout << time;

    return 0;
}