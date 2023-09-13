#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;
long long tree[1000001];
long long high, low, mid;
void input()
{
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        cin >> tree[i];
        if(high <= tree[i])
            high = tree[i];
    }
}

long long sumOfTree(long long h)
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        if(tree[i] > h)
            sum += (tree[i] - h);
    }
    
    return sum;
}

void binSearch()
{
    while (true)    
    {
        mid = (high + low) / 2;
        if(high - low <= 1)
        {
            if(sumOfTree(high) < m)
            {
                cout << low;
                return;
            }

            if(sumOfTree(low) < m)
            {
                cout << high;
                return;
            }

            cout << max(low, high);
            return;
        }

        if(sumOfTree(mid) == m)
        {
            cout << mid;
            return;
        }
        else if(sumOfTree(mid) < m)
            high = mid;
        else
            low = mid;
    }
}

void solve()
{
    input();
    binSearch();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}