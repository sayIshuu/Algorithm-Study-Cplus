//����Ʈ�� ���� ��2     23.04.09    ��3 456 -> 466 10��������
#include <iostream>
using namespace std;

bool arr[300000] = {true, true, false,};
int main(void)
{
//�����佺�׳׽��� ü
    for (int i = 2; i < 300000; i++)
    {
        //�̹� �������ٸ�.
        if(arr[i])
            continue;
        else   //�Ҽ��� false ����
        {
            for (int j = i+i; j < 300000; j+=i)
            {
                arr[j] = true;
            }    
        }
    }

    int n = 1;
    while (true)
    {
        cin >> n;
        if(n==0)
            break;
        int count = 0;
        for (int i = n+1; i <= n+n; i++)
        {
            if(!arr[i])
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}