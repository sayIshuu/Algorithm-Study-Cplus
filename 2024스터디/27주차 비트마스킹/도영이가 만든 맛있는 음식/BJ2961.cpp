#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
//조합을 보는 백트래킹. 넘어가면 볼일없다.
typedef struct
{
    long long s;
    long long b;
}node;

node arr[10];

long long ans = 1111111111;
long long sums;
long long sumb;

void back(int idx)
{
    ans = min(abs(sums - sumb) , ans);

    for (int i = idx+1; i < n; i++)
    {
        sums *= arr[i].s;
        sumb += arr[i].b;
        back(i);
        sums /= arr[i].s;
        sumb -= arr[i].b;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i].s >> arr[i].b;
    
    for (int i = 0; i < n; i++)
    {
        sums += arr[i].s;
        sumb += arr[i].b;
        back(i);
        sums -= arr[i].s;
        sumb -= arr[i].b;
    }
    cout << ans;

    return 0;
}