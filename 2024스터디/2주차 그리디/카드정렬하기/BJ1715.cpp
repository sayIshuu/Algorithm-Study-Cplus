#include <iostream>
#include <queue>
using namespace std;

//자동정렬 필요할 때 우선순위큐! 수직구조로 생각하자 일종의 스택처럼 상상
//일반선언하면 큰수가 위로오기때문에 음수전환을 넣고뺄때 해준다.
int n,sum;
priority_queue<int> pq;
void input()
{
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          int t; cin >> t;
          pq.push(-t);
     }
}
// -t이런게 되나? t*(-1)이렇게 안해도?
void solution()
{
     while (pq.size() > 1)
     {
          int a = -pq.top();
          pq.pop();
          int b = -pq.top();
          pq.pop();
          sum += a;
          sum += b;
          pq.push(-(a+b));
     }
}

void solve()
{
    input();
    solution();
    cout << sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}