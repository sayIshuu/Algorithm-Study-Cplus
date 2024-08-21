#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool visited[10001];
vector<int> v;
vector<int> num;
void back()
{
     if(v.size() == m)
     {
          for (int i = 0; i < m; i++)
          {
               cout << v[i] << " ";
          }
          cout << '\n';
          return;
     }

     for (int i = 0; i < n; i++)
     {
          if(!visited[i])
          {
               v.push_back(num[i]);
               visited[i] = true;
               back();
               visited[i] = false;
               v.pop_back();
          }
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     for (int i = 0; i < n; i++)
     {
          int a; cin >> a;
          num.push_back(a);
     }
     sort(num.begin(), num.end());

     back();

     return 0;
}