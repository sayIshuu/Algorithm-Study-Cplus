//BJ11726 2xn Ÿ�ϸ� ��3 ���̳������α׷���
#include <iostream>
using namespace std;

// �� Ÿ�Ͽ��� ����Ÿ�� �ϳ� �߰��Ѱ� + ���� Ÿ�Ͽ��� ���� Ÿ�� �ΰ� �߰��Ѱ�
// ���� �Ǻ���ġ
// 1 2 3 5 8 13 21 ...
// ������ ���� ���Ѱ� = ���� ���� ������

int main(void)
{
    int tile[1001] = {0,1,2,};

    int n;  cin >> n;

    for (int i = 3; i <= n; i++)
    {
        tile[i] = tile[i-1]%10007 + tile[i-2]%10007;
    }
    
    cout << tile[n]%10007;

    return 0;
}