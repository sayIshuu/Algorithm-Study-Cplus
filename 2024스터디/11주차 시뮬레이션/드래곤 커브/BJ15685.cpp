#include <iostream>
#include <vector>
using namespace std;

int n;

bool map[101][101];

typedef struct
{
     int x, y;
}node;

vector<node> v;
node startNode;
node lastNode;

void nodeCurve(node a)
{
     v.push_back({lastNode.x + (lastNode.y - a.y),lastNode.y - (lastNode.x - a.x)});
     map[v.back().x][v.back().y] = true;
}

void pushSecondNode(int a)
{
     if(a==0)
          v.push_back({startNode.x + 1, startNode.y});
     else if(a==1)
          v.push_back({startNode.x, startNode.y - 1});
     else if(a==2)
          v.push_back({startNode.x - 1, startNode.y});
     else if(a==3)
          v.push_back({startNode.x, startNode.y + 1});

     map[v.back().x][v.back().y] = true;
}

int ans;

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     for (int i = 0; i < n; i++)
     {
          v.clear();

          cin >> startNode.x >> startNode.y;
          v.push_back(startNode);
          map[v.back().x][v.back().y] = true;

          int d;    cin >> d;
          pushSecondNode(d);

          int g; cin >> g;

          for (int j = 0; j < g; j++)
          {
               int size = v.size() - 1;
               lastNode = v.back();
               for (int k = size; k > 0; k--)
               {
                    nodeCurve(v[k-1]);
               }
          }
     }
     
     for (int i = 0; i < 100; i++)
     {
          for (int j = 0; j < 100; j++)
          {
               if(map[i][j] && map[i+1][j] && map[i+1][j+1] && map[i][j+1])
                    ans++;
          }
     }
     
     cout << ans;

     return 0;
}