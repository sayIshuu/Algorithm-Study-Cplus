#include <iostream>
#define MAX 201
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

bool findUnion(int a, int b)
{
    a = getRoot(arr, arr[a]);
    b = getRoot(arr, arr[b]);

    if(a==b) return true;
    else return false;
}

string inputWithSolve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        arr[i] = i;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t; cin >> t;
            if(j >= i && t==1)
                unionRoot(i+1,j+1);
        }    
    }

    int a; cin >> a;
    m--;
    while (m--)
    {
        int b; cin >> b;
        if(!findUnion(a,b))
            return "NO";
        a = b;
    }
    return "YES";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << inputWithSolve();

    return 0;
}