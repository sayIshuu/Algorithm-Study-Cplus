#include <iostream>
#include <algorithm>
using namespace std;

int step[301][4];

int main(void)
{
    int n; cin >> n;

    for (int i = 0; i < n; i++)
        cin >> step[i][3];
    
    step[0][1] = step[0][3];

    for (int i = 1; i < n; i++)
    {
        step[i][0] = max(step[i-1][1], step[i-1][2]);
        step[i][1] = step[i-1][0] + step[i][3];
        step[i][2] = step[i-1][1] + step[i][3];
    }
    
    cout << max(step[n-1][1], step[n-1][2]);
    return 0;
}

//��̴� ���� : ������ĭ�� ��ƾ� �Ѵٴ� ������ ž�ٿ��ĸ� �����ߴµ�
// �׳� ���Ҿ����� �ε��� ä�������� ������ �ε��� Ȯ���� ���� ���־ Ǯ�