#include <iostream>
#include <deque>
using namespace std;

int k =1;
deque<int> S;
void input()
{
     cin >> k;
     int temp = 0;
     for (int i = 0; i < k; i++)
     {
          cin >> temp;
          S.push_back(temp);
     }
}

deque<int> ans;
void solution(int index)
{
    if(ans.size() == 6)
    {
          for (int i = 0; i < ans.size(); i++)
          {
               cout << ans[i] << ' ';
          }
          cout << '\n';
          return;
    }

    for (int i = index; i < k; i++)
    {
          ans.push_back(S[i]);
          solution(i+1);
          ans.pop_back();
    }
}

void solve()
{
     while (k != 0)
     {        
          input();
          solution(0);
          S.clear();
          ans.clear();
          cout << '\n';
     }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}