#include <iostream>
#define MAX 201
#include <string>
using namespace std;

int n,m;
int arr[MAX];

int getRoot(int parent[], int x)  //��Ʈ�� ã���ֱ� ���� ����Լ�
{
    if(parent[x] == x)  //�ڽ��� �ڽ��� �θ��� ���ϴ� �׷����� ��Ʈ��� ��
        return x;
    return parent[x] = getRoot(parent, parent[x]);  //���������鼭 ��Ʈ���� �ֽ�ȭ
}

void unionRoot(int a, int b)    //��Ʈ�� ��ġ�� �װ��� union �ֳ��ϸ� Ʈ�������ϱ�
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