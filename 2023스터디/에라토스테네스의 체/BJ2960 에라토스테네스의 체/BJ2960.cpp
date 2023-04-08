//실4 에라토스테네스의 체 23.04.08
#include <iostream>
using namespace std;

//소수는 false
bool arr[1001];
int main(void)
{
    int n,k; cin >> n >> k;

    for (int i = 2; i <= n; i++)
    {
        if(arr[i])
            continue;
        if(!arr[i])
        {
            for (int j = i; j <= n; j+=i)
            {
                if(arr[j])
                    continue;
                if(k>1)
                {
                    arr[j] = true;
                    k--;
                    continue;
                }
                cout << j;
                return 0;
            }    
        }
    }
    

    return 0;
}