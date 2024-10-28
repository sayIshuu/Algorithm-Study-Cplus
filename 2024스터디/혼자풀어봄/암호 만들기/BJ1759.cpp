#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
char arr[17];

vector<int> v;
bool visited[17];

void backtracking(int index)
{
     if(v.size() == n)
     {
          int mo = 0;
          int ja = 0;
          for (int i = 0; i < n; i++)
          {
               if(arr[v[i]] == 'a' || arr[v[i]] == 'e' || arr[v[i]] == 'i' || arr[v[i]] == 'o' || arr[v[i]] == 'u')
                    mo++;
               else
                    ja++;
          }
          if(mo >= 1 && ja >= 2)
          {
               for (int i = 0; i < n; i++)
                    cout << arr[v[i]];
               cout << '\n';
          }
     }

     for (int i = index; i < m; i++)
     {
          if(visited[i] == true)
               continue;

          visited[i] = true;
          v.push_back(i);
          backtracking(i + 1);
          visited[i] = false;
          v.pop_back();
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     for (int i = 0; i < m; i++)
          cin >> arr[i];
     
     sort(arr, arr+m);

     backtracking(0);

     return 0;
}