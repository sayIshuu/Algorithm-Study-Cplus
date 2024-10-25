#include <iostream>
#define MAX 1000001
#include <string>
using namespace std;

int n,m;
int arr[MAX];

int getRoot(int x)  //��Ʈ�� ã���ֱ� ���� ����Լ�
{
    if(arr[x] == x)  //�ڽ��� �ڽ��� �θ��� ���ϴ� �׷����� ��Ʈ��� ��
        return x;
    return arr[x] = getRoot(arr[x]);  //���������鼭 ��Ʈ���� �ֽ�ȭ
}

void unionRoot(int a, int b)    //��Ʈ�� ��ġ�� �װ��� union �ֳ��ϸ� Ʈ�������ϱ�
{
    a = getRoot(arr[a]);
    b = getRoot(arr[b]);

    if(a<b) arr[b] = a;
    else arr[a] = b;
}

string findUnion(int a, int b)
{
    a = getRoot(arr[a]);
    b = getRoot(arr[b]);

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