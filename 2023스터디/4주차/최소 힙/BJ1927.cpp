#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<long> q;
    int n; cin >> n;

    while (n--)
    {
        long x; cin >> x;

        if(x==0)
        {
            if(q.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << -q.top() << '\n';
            q.pop();
            continue;
        }

        q.push(-x);
    }
    return 0;
}