#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int n;
int k;
set<int> coin;
int numOfCoin[10001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int c;  cin >> c;
        coin.insert(c);
    }
    
    for(int i = 1; i <= k; i++)
        numOfCoin[i] = 100001;

    vector<int> coins(coin.begin(), coin.end());
    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = 1; j <= k; j++)
            if(j-coins[i] >= 0)
                numOfCoin[j] = min(numOfCoin[j], 1+numOfCoin[j-coins[i]]);
    }
    
    if(numOfCoin[k] == 100001)
        cout << -1;
    else
        cout << numOfCoin[k];
    return 0;
}