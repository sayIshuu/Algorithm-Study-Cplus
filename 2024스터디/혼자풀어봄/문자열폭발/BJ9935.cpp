#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s, boom;
vector<char> ans;
char lastBoom;
int cnt;
void input()
{
     cin >> s >> boom;
     lastBoom = boom[boom.length()-1];
}

void solution()
{
     bool isboom = false;
     for (int i = 0; i < s.length(); i++)
     {
          ans.push_back(s[i]);
          if(s[i] == lastBoom)
          {
               isboom = true;
               for (int j = 0; j < boom.length(); j++)
               {
                    if(i-j-cnt < 0)
                    {
                         isboom = false;
                         break;
                    }
                    if(ans[i-j-cnt] != boom[boom.length()-1-j])
                    {
                         isboom = false;
                         break;
                    }
               }
               if(isboom)
               {
                    for (int j = 0; j < boom.length(); j++)
                    {
                         ans.pop_back();
                         cnt++;
                    }
                    
               }

               isboom = false;
          }
     }
     if(ans.empty())
     {
          cout << "FRULA";
     }
     else
     {
          for (int i = 0; i < ans.size(); i++)
          {
               cout << ans[i];
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