//소수 구하기 실3 23.04.09
#include <iostream>
#define MAX 1000001
using namespace std;

bool arr[MAX] = {true, true, false,};
int main(void)
{
    int m, n;   cin >> m >> n;

//========에라토스테네스의 체==================
    for (int i = 2; i < MAX; i++)
    {
        //이미 지워졌다면.
        if(arr[i])
            continue;
        else   //소수는 false 상태
        {
            for (int j = i+i; j < MAX; j+=i)
            {
                arr[j] = true;
            }    
        }
    }
//==============================================
    for (int i = m; i <= n; i++)
    {
        if(!arr[i])
            cout << i << '\n';
    }
    

    return 0;
}