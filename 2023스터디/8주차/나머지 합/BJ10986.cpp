#include <iostream>
using namespace std;

long long arr[1000001];

long long rest[1001] = {1,0,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    long long count = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long t;
        cin >> t;
        arr[i] = arr[i-1] + t;
        t = arr[i]%m;
        rest[t]++;
    }
    
    for (int i = 0; i < m; i++)
        count += (rest[i]*(rest[i]-1) / 2 );
    
    
    cout << count;
    return 0;
}

//������ : ���� ��������� �����ϸ� ���ʿ�� ���� �������� ���ϴ���(�ð�����)�� �����غ���