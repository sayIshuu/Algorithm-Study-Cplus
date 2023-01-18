//BJ2178 미로탐색 실1 알고리즘멘토링 3주차 너비우선탐색
#include <iostream>
#include <string>
#include <queue>
using namespace std;


//문제아이디어 : 어차피 너비우선탐색은 최단거리를 구해낸다. 계층구조로 접근

//큐의 요소가 될 구조체
typedef struct node
{
    int N;
    int M;
    int level;
}Node;


int main(void)
{
    //============2차원배열로 미로 구성===============
    int n,m;
    cin >> n >> m;
    int miro[n][m]; //인덱스접근 -1 주의

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


    //큐가 미로의 위치정보를 가지고 있어야함 => 구조체
    //(0,0)을 기준으로 먼저 넣어줌
    //상하좌우 체크해서 푸쉬해주면서 미로값을 0으로 전환 => 방문체크
    //푸쉬할때 논리적 거리를 계층변수로 두어 푸쉬된 각각의 요소가
    //거리정보를 가지고 있게함.
    //목적지 도착하면 거리정보 출력하고 break;

    queue<Node> q;
    q.push({0,0,1});
    
    while (!q.empty())
    {
        Node front = q.front();
        //목적지 도착하면 목적지 레벨 출력하고 끝
        if(q.back().N == n-1 && q.back().M == m-1)
        {
            cout << q.back().level;
            break;
        }
        //우
        if(front.N+1 >= 0 && front.N+1 < n)
        {
            if(miro[front.N+1][front.M] == 1)
            {
                q.push({front.N+1,front.M,front.level+1});
            }
        }
        //하
        if(front.M+1 >= 0 && front.M+1 < m)
        {
            if(miro[front.N][front.M+1] == 1)
            {
                q.push({front.N,front.M+1,front.level+1});
            }
        }
        //좌
        if(front.N-1 >= 0 && front.N-1 < n)
        {
            if(miro[front.N-1][front.M] == 1)
            {
                q.push({front.N-1,front.M,front.level+1});
            }
        }
        //상
        if(front.M-1 >= 0 && front.M-1 < m)
        {
            if(miro[front.N][front.M-1] == 1)
            {
                q.push({front.N,front.M-1,front.level+1});
            }
        }

        //맨앞노드 방문체크하고 팝
        miro[front.N][front.M] = 0;
        q.pop(); 
    }
    return 0;
}
