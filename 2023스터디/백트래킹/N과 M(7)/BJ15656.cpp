#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n,m;
deque<int> ans;
int arr[8];

void back()
{
    if(ans.size() == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        ans.push_back(arr[i]);
        back();
        ans.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    back();
    return 0;
}