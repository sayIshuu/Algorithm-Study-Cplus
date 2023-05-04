//�Ҽ� ���ϱ� ��3 23.04.09
#include <iostream>
#define MAX 1000001
using namespace std;
//�Ҽ��� false
bool isPrime[MAX] = {true, true, false,};
int m, n;

//�����佺�׳׽��� ü
void primeCheck(){
    for (int i = 2; i < MAX; i++)
    {
        if(isPrime[i])
            continue;
        else{ //else ó���Ҷ� �ð����⵵�� ������
            for (int j = i+i; j < MAX; j+=i) // i+i �� i*2���� ����
                isPrime[j] = true;
        }
    }
}

int main(void)
{
    cin >> m >> n;

    primeCheck();
    for (int i = m; i <= n; i++)
    {
        if(!isPrime[i])
            cout << i << '\n';
    }
    

    return 0;
}