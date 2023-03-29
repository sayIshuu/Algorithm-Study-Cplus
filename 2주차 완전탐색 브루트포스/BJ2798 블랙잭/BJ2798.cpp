#include <iostream>
using namespace std;

//문제아이디어 브루트포스. 
//첫번째숫자잡고 두번째숫자 잡고 나머지돌리고
//두번째숫자 하나 올리고 나머지 돌리고
//포문 3개..인수는 a가 연결되게

int arr[101];

int main(void)
{
    int n; cin >> n;
    int m; cin >> m;

    for (int a = 0; a < n; a++)
    {
        cin >> arr[a];
    }
    
    int sum = 0;
    int ans = 0;
    for (int a = 0; a < n-2; a++)
    {
        sum = arr[a];
        if(sum > m) continue;
        for (int b = a+1; b < n-1; b++)
        {
            sum = arr[a];
            sum += arr[b];
            if(sum > m) continue;
            for (int c = b+1; c < n; c++)
            {
                sum = arr[a]+arr[b];
                sum += arr[c];
                if(sum > m) continue;
                if(sum == m)
                {
                    cout << sum;
                    return 0;
                }
                if(sum > ans) ans = sum;
            }            
        }    
    }
    
    cout << ans << endl;
    return 0;
}