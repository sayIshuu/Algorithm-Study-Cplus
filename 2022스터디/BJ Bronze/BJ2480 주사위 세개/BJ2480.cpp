//BJ2480 �ֻ��� ���� ��4
#include <iostream>
#include <vector>
using namespace std;

/*
�������̵��
1~6 ���� ���� �ٸ� �������� �����ϰų� ���Ⱑ �����ϱ�
�迭�� �ε����� ���Ǻи����ϰ�
������ ī������ �Ѵ�.
*/

//�ε����� n-1�̹Ƿ� 0�� �ε����� �Ⱦ��� ���ε�� 7��¥�� �迭����
vector<int> noon(7);

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;

    noon[a]++;
    noon[b]++;
    noon[c]++;

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        if(noon[i] == 3)
        {
            cout << 10000 + i*1000 << endl;
            break;
        }
        else if(noon[i] == 2)
        {
            cout << 1000 + i*100 << endl;
            break;
        }
        else if(noon[i] == 1)
        {
            count++;
            if(count == 3)
            {
                cout << i*100 << endl;
                break;
            }
        }
    }
    
    return 0;
}