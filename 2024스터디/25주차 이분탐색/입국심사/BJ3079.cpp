#include <iostream>
#include <vector>
#include <algorithm>
/*
ㅡ ㅡ|ㅡ ㅡ|ㅡ ㅡ|ㅡ ㅡ
ㅡ ㅡ ㅡ|ㅡ ㅡ ㅡ|ㅡ ㅡ ㅡ
ㅡ ㅡ ㅡ|ㅡ ㅡ ㅡ
ㅡ ㅡ ㅡ ㅡ
ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ
ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ
ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ ㅡ
*/

using namespace std;

long long n, m;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());

    long long start = 1;
    long long end = arr[0] * m;
    long long ans = 0;
    while(start <= end){
        long long mid = (start + end) / 2;
        long long cnt = 0;
        for(int i = 0; i < n; i++)
            cnt += mid / arr[i];
        
        if(cnt >= m){
            ans = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    cout << ans;
    return 0;
}