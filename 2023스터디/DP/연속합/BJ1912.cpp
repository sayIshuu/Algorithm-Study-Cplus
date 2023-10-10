#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100001];
long long sum, maxSum;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++)
    {
        if(sum+arr[i] >= 0)
        {
            sum += arr[i];
            maxSum = max(maxSum, sum);
        }
        else{
            sum = 0;
            while(arr[i] <= 0)
                i++;
            i--;
        }
    }

    bool c = false;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            c = true;
            break;
        }
    }

    if(!c)
        maxSum = *max_element(arr, arr+n);
    cout << maxSum;
    return 0;
}