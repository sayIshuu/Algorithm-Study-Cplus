#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

int p[4001];
int m[4001];

int main(void)
{
    int n; cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int t = 0; cin >> t;
        v.push_back(t);
        if(t >= 0)
        {
            p[t]++;
            continue;
        }
        else
            m[t*-1]++;
    }

    cout << (int)round((double)accumulate(v.begin(), v.end(), 0)/n) << '\n';

    sort(v.begin(), v.end());
    //sort위치 바꿔서 시간복잡도 체크해보자
    cout << v[n/2] << '\n';

    int ma = max(*max_element(p, p+4001), *max_element(m,m+4001));
    int count = 2;
    int many = 0;
    bool one = true;
    for (int i = 4000; i > 0; i--)
    {
        if(m[i] == ma)
        {
            many = i*-1;
            count--;
            if(count == 0)
            {
                cout << many << '\n';
                one = false;
                break;
            }
        }
    }
    for (int i = 0; i < 4001; i++)
    {
        if(p[i] == ma)
        {
            many = i;
            count--;
            if(count == 0)
            {
                cout << many << '\n';
                one = false;
                break;
            }
        }
    }
    if(one)
    {
        cout << many << '\n';
    }
    
    cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(),v.end());

    return 0;
}