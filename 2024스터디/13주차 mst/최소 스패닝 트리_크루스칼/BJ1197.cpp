#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
// ������ �ʸ������� �� ���Ƽ� ������ �� �����ϴ�.
// �ٵ� ũ�罺Į�� Ǯ���.

int a,b,cnt;
long long c,sum;

//union find�� ���� �迭
int parent[10001];

//��Ʈ ã��
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

//���� ����ü
typedef struct
{
     int a,b;
     long long c;
} Edge;

//���� ���� ����
vector<Edge> edge;

//sort �Լ��� ���� �� �Լ�. ����� ���� ������ ����
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
     //���� ��� �������� ����
     sort(edge.begin(), edge.end(), cmp);

     //union find �ʱ�ȭ
     for (int i = 1; i <= v; i++)
          parent[i] = i;
     
     //���� �ϳ��� Ž��
     for (int i = 0; i < edge.size(); i++)
     {
          //����Ŭ�� ������ �ʴ´ٸ�
          if (!isCycle(edge[i].a, edge[i].b))
          {
               //���� ��� ���ϱ�
               sum += edge[i].c;
               //���� ����
               unionRoot(edge[i].a, edge[i].b);
               cnt++;

               if(cnt == v-1)
                    break;
          }
     }
     cout << sum << '\n';

     return 0;
}