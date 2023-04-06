#include <iostream>
#include <queue>
using namespace std;

//문제아이디어 :
//초기 설정 0 : 빈공간, 1: 치즈..... 현재개수 count 저장
//구멍찾기 : 2 (BFS)
//c 찾기 : 3 (BFS)
//c 녹이기, hour++
//2 -> 0으로 초기화.
//반복.
//현재개수 0이면 hour랑 이전 count 출력.

int n,m;
int map[101][101] = {};

typedef struct node
{
    int x;
    int y;
}NODE;

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


    queue<NODE> q;



    return 0;
}