#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int M[501][501];
int d[501];

int minmumM(int i, int j)
{
    int mini = INT_MAX;
    if(i==j)
        return 0;

    if(M[i][j] != 0)
        return M[i][j];

    if(i+1 == j)
        return M[i][j] = d[i-1]*d[i]*d[j];

    for (int k = i; k < j; k++)
        mini = min(mini, minmumM(i,k) + minmumM(k+1,j) + d[i-1]*d[k]*d[j]);
    return M[i][j] = mini;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i] >> d[i+1];
    
    cout << minmumM(1,n);
    return 0;
}