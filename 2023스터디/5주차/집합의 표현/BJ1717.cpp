#include <iostream>
#define MAX 1000001
#include <string>
using namespace std;

int n,m;
int arr[MAX];

int getRoot(int parent[], int x)  //루트를 찾아주기 위한 재귀함수
{
    if(parent[x] == x)  //자신이 자신의 부모라면 속하는 그래프의 루트라는 뜻
        return x;
    return parent[x] = getRoot(parent, parent[x]);  //빠져나오면서 루트정보 최신화
}

void unionRoot(int a, int b)    //루트를 합치면 그것이 union 왜냐하면 트리구조니까
{
    a = getRoot(arr, arr[a]);
    b = getRoot(arr, arr[b]);

    if(a<b) arr[b] = a;
    else arr[a] = b;
}

string findUnion(int a, int b)
{
    a = getRoot(arr, arr[a]);
    b = getRoot(arr, arr[b]);

    if(a==b) return "YES";
    else return "NO";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        arr[i] = i;

    while (m--)
    {
        int select; cin >> select;
        int a,b; cin >> a >> b;
        if(select == 1)
            cout << findUnion(a,b) << '\n';
        else
            unionRoot(a,b);
    }
    return 0;
}