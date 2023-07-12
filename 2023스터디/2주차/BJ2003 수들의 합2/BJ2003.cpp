#include <iostream>
using namespace std;
//투포인터, 누적합
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; long long m; cin >> n >> m;

    int arr[n];
    long long sum[n+1];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }

    int end = 1;
    int answer = 0;

    for (int start = 0; start < n; start++)
    {
        if(end == start)
            end++;
        
        long long ls;
        if(end <= n)
            ls = sum[end] - sum[start];
        else
            ls = sum[n] - sum[start];

        if(ls > m)
            continue;
        else if (ls < m)
        {
            if(end >= n)
                break;
            end++;
            start--;
            continue;
        }
        else if (ls == m)
        {
            answer++;
            if(end >= n)
                break;
            
            end++;
            start--;
            continue;
        }
    }
    
    cout << answer;
    
    return 0;
}