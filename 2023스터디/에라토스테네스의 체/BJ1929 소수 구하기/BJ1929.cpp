//�Ҽ� ���ϱ� ��3 23.04.09
#include <iostream>
#define MAX 1000001
using namespace std;

bool arr[MAX] = {true, true, false,};
int main(void)
{
    int m, n;   cin >> m >> n;

    for (int i = 2; i < MAX; i++)
    {
        //�̹� �������ٸ�.
        if(arr[i])
            continue;
        else   //�Ҽ��� false ����
        {
            for (int j = i+i; j < MAX; j+=i)
            {
                arr[j] = true;
            }    
        }
    }

    for (int i = m; i <= n; i++)
    {
        if(!arr[i])
            cout << i << '\n';
    }
    

    return 0;
}