//GCD 합 실4 유클리드 호제법 23.05.10   실2520 ->
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    
    return gcd(b,a%b);
}

int main(void)
{
    int t; cin >> t;

    for (int i = 0; i < t; i++)
    {
        //(long long 주의!)(long long 주의!)(long long 주의!)(long long 주의!)
        long long sum =0;
        int n; cin >> n;
        int arr[n];
        if(n==1){
            cout << sum <<'\n';
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];    
        }
        
        for (int j = 0; j < n; j++)
        {
            for (int m = j+1; m < n; m++)
            {
                sum += gcd(arr[j],arr[m]);
            }           
        }
        
        cout << sum << '\n';
    }
    return 0;
}