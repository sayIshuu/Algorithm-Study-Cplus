#include <iostream>
#include <algorithm>
using namespace std;

int a,b,c,d,e,f;

void input()
{
     cin >> a >> b >> c >> d >> e >> f;
}

void solution()
{
    for (int x = -999; x < 1000; x++)
    {
          for (int y = -999; y < 1000; y++)
          {
               if((a*x + b*y)==c && (d*x + e*y)==f)
               {
                    cout << x << ' ' << y;
               }
          }
    }
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}