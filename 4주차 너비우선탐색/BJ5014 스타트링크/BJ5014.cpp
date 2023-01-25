//BJ5014 스타트링크 실1 언타멘토링4주차 너비우선탐색
#include <iostream>
#include <queue>
using namespace std;

//인덱스는 층, 값 0은 방문전, 1은 방문
int arr[1000000] = {0,};

typedef struct node
{
    int curPos;
    int time;
}Node;

int main(void)
{
    //꼭대기, 현위치, 목적지, up, down
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    if(s==g) {cout << 0; return 0;}

    queue<Node> q;
    q.push({s,0});
    arr[s] = 1;
    while (!q.empty())
    {
        int x = q.front().curPos;
        int time = q.front().time;
        q.pop();       

        if(x+u == g || x-d == g) { cout << time+1; return 0; }

        //범위안넘어가게 확인하면서 push.. 그러다 목표값k찾으면 break;
        //x+1
        if(x+u <= f)
        {
            if(arr[x+u] == 0)
            {
                //방문체크
                arr[x+u] = 1;
                q.push({x+u, time+1});
            }
        }
        //x-1
        if(x-d >= 1)
        {
            if(arr[x-d] == 0)
            {
                //방문체크
                arr[x-d] = 1;
                q.push({x-d, time+1});   
            }             
        }
    }
    cout << "use the stairs" << endl;

    return 0;
}