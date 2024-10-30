#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
//�̰͵� ������ �������� Ǯ��������� ũ�罺Į�� Ǯ���.
int a,b,c,cnt;
long long sum;

int parent[1001];

int getRoot(int x)
{
     if(parent[x] == x)
          return x;
     return parent[x] = getRoot(parent[x]);
}

bool isCycle(int a, int b)
{
     a = getRoot(a);
     b = getRoot(b);
     if(a==b)
          return true;
     return false;
}

void unionRoot(int a, int b)
{
     a = getRoot(a);
     b = getRoot(b);
     if(a<b)
          parent[b] = a;
     else
          parent[a] = b;
}

typedef struct
{
     int a,b,c;
}Edge;

vector<Edge> edge;

bool cmp(Edge a, Edge b)
{
     return a.c < b.c;
}

void input()
{
     cin >> n >> m;
     for (int i = 1; i <= n; i++)
          parent[i] = i;
     while (m--){
          cin >> a >> b >> c;
          edge.push_back({a,b,c});
     }
     sort(edge.begin(), edge.end(), cmp);
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     input();

     for (int i = 0; i < edge.size(); i++){
          if(!isCycle(edge[i].a, edge[i].b)){
               unionRoot(edge[i].a, edge[i].b);
               sum += edge[i].c;
               cnt++;
               if(cnt == n-1)
                    break;
          }
     }
     cout << sum << '\n';

     return 0;
}