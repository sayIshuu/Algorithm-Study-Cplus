#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> worker(100005);
long long sum[100005];
long long reward[100005];

//메모라이제이션? 그거 해야되네
void back(int _boss, long long _reward)
{
     sum[_boss] += _reward;
     if(worker[_boss].empty())
          return;

     for (int i = 0; i < worker[_boss].size(); i++)
     {
          if(reward[worker[_boss][i]] != 0)
          {
               reward[worker[_boss][i]] += _reward;
               continue;
          }
          back(worker[_boss][i], _reward);
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     int b; cin >> b;
     for (int i = 2; i <= n; i++)
     {
          cin >> b;
          worker[b].push_back(i);
     }

     long long r;
     for (int i = 0; i < m; i++)
     {
          cin >> b >> r;
          reward[b] += r;
     }

     for (int i = 2; i <= n; i++)
     {
          if(reward[i] != 0)
          {
               back(i,reward[i]);
          }
     }
     

     for (int i = 1; i <= n; i++)
     {
          cout << sum[i] << ' ';
     }

     return 0;
}