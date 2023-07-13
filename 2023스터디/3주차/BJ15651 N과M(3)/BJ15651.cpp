#include <iostream>
#include <deque>
using namespace std;

int n,m;
deque<int> ans;

void back(int s)    //시작은 1부터
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

    for (int i = 1; i <= n; i++)
    {
        ans.push_back(i);
        back(i+1);
        ans.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    back(1);
    return 0;
}