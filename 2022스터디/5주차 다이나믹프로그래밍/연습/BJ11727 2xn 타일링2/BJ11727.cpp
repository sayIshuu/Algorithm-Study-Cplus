//BJ11727 2xnŸ�ϸ�2 ��3 ���̳������α׷���
#include <iostream>
using namespace std;

int main(void)
{
    int tile[1001] = {0,1,3,};

    int n;  cin >> n;

    for (int i = 3; i <= n; i++)
    {
        tile[i] = tile[i-1]%10007 + (tile[i-2]*2)%10007;
    }
    
    cout << tile[n]%10007;

    return 0;
}