//BJ2178 미로탐색 실1 알고리즘멘토링 3주차 너비우선탐색
#include <iostream>
#include <string>
#include <queue>
using namespace std;

/* 문제아이디어
최단경로빼곤 바이러스 문제와 동일.. 미로는 2차원배열로 구성하겠음.
새로운 요소 push될때마다 answer++;
pop하기전에 인접한 것들 푸쉬하잖아? 푸쉬하는게 없다면 끝에 몰린것. 그러면 answer--;
큐가 empty되면 끝 단 마지막 골에서도 끝에 몰린것 처리되므로 answer -1 출력
*/

//큐의 요소가 될 구조체
typedef struct node
{
    int N;
    int M;
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


    //큐가 미로의 위치정보를 가지고 있어야함...구조체 쓰고싶다..이게어렵네
    //(1,1)을 기준으로 먼저 넣어줌
    //반복문 while(!q.empty)
    //  큐.front() (n,m)범위의 인접한 상하좌우칸 중 값이 1인 칸 있느냐?
    //  없으면 answer--;
    //  있으면 push하고 answer++;
    //  q.front()에 해당하는 미로 칸 = 0    ..방문체크
    //  q.pop();
    //답은 answer+2; 첫노드 안들어가고 마지막 노드에서 -1 돼.
    
    int answer = 0;

    queue<Node> q;
    q.push({1,1});
    
    while (!q.empty())
    {
        Node front = q.front();
        //아래 조건문들 돌며 count가 0이 유지되면 막다른길. 따라서 answer--;해줌
        int count = 0; 
        if(q.back().M == m && q.back().n == n)
            cout << answer+2;
        //우
        if(front.N+1 >= 0 && front.N+1 <= n)
        {
            if(miro[front.N+1][front.M] == 1)
            {
                q.push({front.N+1,front.M});
                answer++;
                count++;
                continue;
            }
        }
        //하
        if(front.M+1 >= 0 && front.M+1 <= m)
        {
            if(miro[front.N][front.M+1] == 1)
            {
                q.push({front.N,front.M+1});
                answer++;
                count++;
                continue;
            }
        }
        //좌
        if(front.N-1 >= 0 && front.N-1 <= n)
        {
            if(miro[front.N-1][front.M] == 1)
            {
                q.push({front.N-1,front.M});
                answer++;
                count++;
                continue;
            }
        }
        //상
        if(front.M-1 >= 0 && front.M-1 <= m)
        {
            if(miro[front.N][front.M-1] == 1)
            {
                q.push({front.N,front.M-1});
                answer++;
                count++;
                continue;
            }
        }
        if(count == 0)
            answer--;

        //맨앞노드 방문체크하고 팝
        miro[front.N][front.M] = 0;
        q.pop(); 
    }
    

    cout << answer+2;
}


//오답. 깊이우선탐색엔 도움될지 모르지만 오답임.