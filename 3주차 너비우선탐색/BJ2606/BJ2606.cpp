//BJ2606 바이러스 실3 언타멘토링 3주차 프리뷰
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    //정점개수
    int n; 
    cin >> n;
    //링크개수
    int l;
    cin >> l;

    list<int> arr[n];     // -1 신경쓰기
    int check[n] = {0,};  // 0이면 해당되는 정점 방문 안한것

    //인접리스트 만들기
    for (int i = 0; i < l; i++)
    {
        int x,y;
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    //너비우선탐색 시작
    list<int> q;

    q.push_front(1);
    check[0] = 1;

    int count = 0;

    for (int i = 0; i <= arr[q.front-1].size()/*q의 맨앞원소의 인접리스트*/; i++)
    {
        if (check[arr[q.front-1].front()-1] == 0)
        {
            check[arr[q.front-1].front()-1] = 1;
            q.push_back(arr[q.front-1].pop_front());
            count++;
        }
    }



    cout << count << endl;
    return 0;
}
