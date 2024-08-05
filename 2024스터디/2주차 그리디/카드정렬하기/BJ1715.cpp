#include <iostream>
#include <queue>
using namespace std;

//�ڵ����� �ʿ��� �� �켱����ť! ���������� �������� ������ ����ó�� ���
//�Ϲݼ����ϸ� ū���� ���ο��⶧���� ������ȯ�� �ְ��� ���ش�.
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
// -t�̷��� �ǳ�? t*(-1)�̷��� ���ص�?
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