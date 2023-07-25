#include <iostream>
using namespace std;

int n;
long long s;
int arr[100004];
long long sum[200002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i+1] = sum[i]+arr[i];
        if(arr[i] >= s)
        {
            cout << 1;
            return 0;
        }
    }
    
    int first = 0;
    int last = 1;
    int ans = 200005;   //최소가 답이니까 큰수로 디폴트
    for (first = 0; first < n; first++)
    {
        if(first == last)
            last++;

        if(sum[last+1]-sum[first] < s)
        {
            if(last >= n)
                break;
            last++;
            first--;
            continue;
        }
        else{
            if(last-first < ans)
            {
                ans = last-first;
                continue;
            }
        }
    }
    if(ans==200005)
    {
        cout << 0;
        return 0;
    }
    cout << ans+1;
    return 0;
}