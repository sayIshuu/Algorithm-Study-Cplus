#include <iostream>
using namespace std;

int n, root, terminateRoot;
int parent[51];
bool isLeaf[51];

int input()
{
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          isLeaf[i] = true;
          cin >> parent[i];
          if(parent[i] == -1) root = i;
     }
     cin >> terminateRoot;
     return terminateRoot;
}

void dfs(int _n)
{
     if(isLeaf[_n])
     {
          isLeaf[_n] = false;
          return;
     }

     for (int i = 0; i < n; i++)
     {
          if(parent[i] == _n) dfs(i);
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     
     if(input() == root)
     {
          cout << 0; 
          return 0;
     }

     for (int i = 0; i < n; i++)
     {
          if(i == root) continue;
          isLeaf[parent[i]] = false;
     }
     
     dfs(terminateRoot);

     int cnt = 1;
     for (int i = 0; i < n; i++)
     {
          if(i!= terminateRoot && parent[i] == parent[terminateRoot])
          {
               cnt--; break;
          }
     }

     for (int i = 0; i < n; i++)
          if(isLeaf[i])  cnt++;

     cout << cnt;

     return 0;
}