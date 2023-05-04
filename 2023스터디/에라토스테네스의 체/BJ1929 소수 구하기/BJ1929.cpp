//소수 구하기 실3 23.04.09
#include <iostream>
#define MAX 1000001
using namespace std;
//소수는 false
bool isPrime[MAX] = {true, true, false,};
int m, n;

//에라토스테네스의 체
void primeCheck(){
    for (int i = 2; i < MAX; i++)
    {
        if(isPrime[i])
            continue;
        else{ //else 처리할때 시간복잡도가 빨라짐
            for (int j = i+i; j < MAX; j+=i) // i+i 가 i*2보다 빠름
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