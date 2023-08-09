#include <iostream>
#include <algorithm>
using namespace std;

int n;
int day[15];
int pay[15];
int maxpay[16];

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> day[i] >> pay[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        pay[i] += maxpay[i];
        for (int j = i+day[i]; j <= n; j++)
        {
            maxpay[j] = max(maxpay[j], pay[i]);
        } 
    }
    cout << maxpay[n];
    return 0;
}