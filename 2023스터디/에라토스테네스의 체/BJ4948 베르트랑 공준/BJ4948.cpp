//베르트랑 공준 실2     23.04.09    실3 456 -> 466 10점오르네
#include <iostream>
using namespace std;

bool arr[300000] = {true, true, false,};
int main(void)
{
//에라토스테네스의 체
    for (int i = 2; i < 300000; i++)
    {
        //이미 지워졌다면.
        if(arr[i])
            continue;
        else   //소수는 false 상태
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