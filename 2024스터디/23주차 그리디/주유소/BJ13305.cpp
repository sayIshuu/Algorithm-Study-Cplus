#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long curPrice;
long long sum;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> kms;
    vector<long long> prices;

    cin >> n;
    long long temp = 0;
    for (int i = 0; i < n-1; i++){
        cin >> temp;
        kms.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        cin >> temp;
        prices.push_back(temp);
    }
    
    curPrice = prices[0];
    
    for (int i = 0; i < n-1; i++)
    {
        sum += curPrice*kms[i];
        curPrice = min(curPrice,prices[i+1]);
    }
    
    cout << sum;
    return 0;
}