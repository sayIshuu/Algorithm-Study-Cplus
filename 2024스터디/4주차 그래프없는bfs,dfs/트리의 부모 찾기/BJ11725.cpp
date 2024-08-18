#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;



int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     vector<vector<int>> v(n+1);
     int arr[n+1] = {-1,-1,0,};
     for (int i = 1; i < n; i++)
     {
          int a,b;
          cin >> a >> b;
          v[a].push_back(b);
          v[b].push_back(a);
     }
     
     queue<int> q;

     q.push(1);
     while (!q.empty())
     {
          int x = q.front();
          q.pop();

          for (int i = 0; i < v[x].size(); i++)
          {
               if(arr[v[x][i]] != 0) continue;
               q.push(v[x][i]);
               arr[v[x][i]] = x;
          }
     }
     
     for (int i = 2; i <= n; i++)
     {
          cout << arr[i] << '\n';
     }
     
     return 0;
}