//BJ1697 숨바꼭질 실1 언타멘토링4주차 너비우선탐색_2
#include <iostream>
#include <queue>
using namespace std;

//최단거리문제 => 너비우선탐색
//너비우선 탐색을 위해 선형자료를 트리,그래프 등의 구조로 이해

//인덱스는 점의 위치, 값이 0이면 방문 전. 1이면 방문.
int arr[100000] = {0,};

typedef struct node
{
    int curPos;
    int time;
}Node;


int main(void)
{   
    int n, k;
    cin >> n >> k;


    //동생이 등잔밑이 어둡다 작전을 썼을때
    if(n==k) { cout << 0; return 0; }

    queue<Node> q;
    q.push({n,0});
    arr[n] = 1;
    while (!q.empty())
    {
        int x = q.front().curPos;
        int time = q.front().time;
        q.pop();       

        if(x+1 == k || x-1 == k || x*2 == k) { cout << time+1; break; }

        //범위안넘어가게 확인하면서 push.. 그러다 목표값k찾으면 break;
        //x+1
        if(x+1 <= 100000)
        {
            if(arr[x+1] == 0)
            {
                //방문체크
                arr[x+1] = 1;
                q.push({x+1, time+1});
            }
        }
        //x-1
        if(x-1 >= 0)
        {
            if(arr[x-1] == 0)
            {
                //방문체크
                arr[x-1] = 1;
                q.push({x-1, time+1});   
            }             
        }
        //x*2
        if(x*2 <= 100000)
        {
            if(arr[x*2] == 0)
            {    
                //방문체크
                arr[x*2] = 1;
                q.push({x*2, time+1});
            }
        }
    }

    return 0;
}