//BJ2606 바이러스 실3 언타멘토링 3주차 프리뷰 너비우선탐색
#include <iostream>
//#include <list>
#include <vector> // 피드백따라서 list가 아닌 vector로 인접리스트 및 큐 구현해보겠음
#include <queue>
using namespace std;

/* 문제 아이디어 - 2 인접리스트 이용한 구현
그래프 구현과 동시에 각 노드의 인접리스트 작성 by vector
큐 구현, 1 push...1방문체크
큐 맨앞 노드(1) 인접리스트 가져와서 방문체크 후 큐에 push하고 방문체크, 1 pop
반복
큐 empty되면 종료. pop할때마다 count해서 정답은 count-1;
*/
// 너비우선탐색은 선입선출인 큐로 구현한다.




int main(void)
{
    //정점개수
    int n; 
    cin >> n;
    //링크개수
    int l;
    cin >> l;

    //인덱스 -1 신경안쓰려고 101. 0번인덱스는 안씀
    vector<vector<int>> nearList(101);  
    vector<int> v;     
    nearList.push_back(v);

    //방문체크) 0이면 해당되는 정점 방문 안한것 1이면 참 => 그대로 조건으로 활용해도 댐.
    int check[101] = {0,};  

    //인접리스트 만들기
    for (int i = 0; i < l; i++)
    {
        int x,y;
        cin >> x >> y;
        nearList[x].push_back(y);
        nearList[y].push_back(x);
    }
    

    queue<int> q;
    //pop한 개수-1이 답이라서 count = -1;
    int count = -1;

    q.push(1);
    check[1] = 1;

    while (!q.empty())
    {
        vector<int> firstList(nearList[q.front()]);
        //큐 맨앞 요소의 인접리스트(nearList[q.front()])를 큐에 push
        for (int i = 0; i < firstList.size(); i++)
        {
            if(check[firstList[i]] == 0)
            {
                q.push(firstList[i]);
                check[firstList[i]] = 1;
            }
        }
        q.pop();
        count++;
    }
    
    
    cout << count << endl;
    
    return 0;
}


//test vector nearlist에서 크기 지정 안하는법
//test while문에서 queue.push(nearlist) 되는지