#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
// 간선이 십만까지로 더 많아서 프림이 더 적합하다.
// 근데 크루스칼로 풀어보자.

int a,b,cnt;
long long c,sum;

//union find를 위한 배열
int parent[10001];

//루트 찾기
int getRoot(int x)
{
     if (parent[x] == x)
          return x;
     return parent[x] = getRoot(parent[x]);
}

bool isCycle(int a, int b)
{
     a = getRoot(a);
     b = getRoot(b);
     if (a == b)
          return true;
     return false;
}

void unionRoot(int a, int b)
{
     a = getRoot(a);
     b = getRoot(b);
     if (a < b)
          parent[b] = a;
     else
          parent[a] = b;
}

//간선 구조체
typedef struct
{
     int a,b;
     long long c;
} Edge;

//간선 저장 벡터
vector<Edge> edge;

//sort 함수를 위한 비교 함수. 비용이 작은 순으로 정렬
bool cmp(Edge a, Edge b)
{
     return a.c < b.c;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     
     cin >> v >> e;
     while (e--)
     {
          cin >> a >> b >> c;
          edge.push_back({a,b,c});
     }
     //간선 비용 오름차순 정렬
     sort(edge.begin(), edge.end(), cmp);

     //union find 초기화
     for (int i = 1; i <= v; i++)
          parent[i] = i;
     
     //간선 하나씩 탐색
     for (int i = 0; i < edge.size(); i++)
     {
          //사이클이 생기지 않는다면
          if (!isCycle(edge[i].a, edge[i].b))
          {
               //간선 비용 더하기
               sum += edge[i].c;
               //간선 연결
               unionRoot(edge[i].a, edge[i].b);
               cnt++;

               if(cnt == v-1)
                    break;
          }
     }
     cout << sum << '\n';

     return 0;
}