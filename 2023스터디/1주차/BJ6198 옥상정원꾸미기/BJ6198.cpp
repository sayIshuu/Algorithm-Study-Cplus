#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;

    stack<int> s;

    long long sum = 0;
    while (n--)
    {
        int h; cin >> h;
        if(s.empty())
        {
            s.push(h);
            continue;
        }
        else
        {
            if(s.top() > h)
            {
                sum += s.size();
                s.push(h);
                continue;
            }
            else
            {
                while(s.top() <= h)
                {
                    s.pop();
                    if(s.empty())
                        break;
                }
                sum += s.size();
                s.push(h);
            }
        }
    }
    
    
    cout << sum;
    return 0;
}