//BJ11568 민균이의 계략 실2
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int ans[1001];

int main(void)
{
    int n;  cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ans[i] = 1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if(arr[j] < arr[i])
            {
                if(ans[j] >= ans[i])
                    ans[i]++;
            }
        }  
    }
    
    cout << *max_element(begin(ans),end(ans)) << endl;
    return 0;
}
//마지막숫자가 젤 클거란 보장이 없음.