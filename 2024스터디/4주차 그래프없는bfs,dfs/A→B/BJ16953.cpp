#include <iostream>
#include <queue>
using namespace std;

typedef struct
{
     long long x; int depth;
}node;

long long a,b;
//방문체크 없는 bfs 풀이

queue<node> q;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> a >> b;

     q.push({a,1});

     while (!q.empty())
     {
          long long x = q.front().x;
          int depth = q.front().depth;

          if(x==b)
          {
               cout << depth;
               break;
          }
          q.pop();

          long long nx = x*2;
          if(nx <= b) q.push({nx,depth+1});

          nx = (x*10) +1;
          if(nx > b) continue;
          q.push({nx,depth+1});
     }

     if(q.empty())
     {
          cout << -1;
     }

     return 0;
}
