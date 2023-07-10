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
// &&기준으로 순서 바꾸면 답 안나옴 스택이 비어있는데 top을 참조할 수 없으니까
// 조건문에서 &&연산자는 앞조건 불일치면 바로 끊어버린다
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