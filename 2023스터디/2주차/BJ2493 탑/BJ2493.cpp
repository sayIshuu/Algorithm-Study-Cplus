#include <iostream>
#include <stack>
using namespace std;

typedef struct
{
    int index;
    int num;
}node;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    stack<node> s;
    int a; cin >> a;
    s.push({1,a});
    cout << 0 << ' ';
    for (int i = 2; i <= n; i++)
    {
        int t; cin >> t;
// &&�������� ���� �ٲٸ� �� �ȳ��� ������ ����ִµ� top�� ������ �� �����ϱ�
// ���ǹ����� &&�����ڴ� ������ ����ġ�� �ٷ� ���������
        while (!s.empty() && s.top().num < t )
        {
            s.pop();
        }
        
        if(s.empty())
        {
            cout << 0 << ' ';
            s.push({i,t});
        }
        else{
            cout << s.top().index << ' ';
            s.push({i,t});
        }
    }
    
    return 0;
}