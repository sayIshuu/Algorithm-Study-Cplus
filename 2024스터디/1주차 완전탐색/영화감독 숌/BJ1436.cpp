#include <iostream>
#include <string>
using namespace std;

int n;
int i = 1;
void input()
{
     cin >> n;
}

void solution(int a)
{
    if(to_string(a).find("666") != string::npos)
          n--;
}

void solve()
{
    input();
    while (true)
    {
          solution(i);
          if(n==0)
          {
               cout << i;
               break;
          }
          i++;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}