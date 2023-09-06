#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n,ma;
//map<string, int> m; O(LogN)
unordered_map<string, int> m; //O(1)
vector<string> ans;

void input()
{
    cin >> n >> ma;
    for (int i = 0; i < n+ma; i++)
    {
        string s;   cin >> s;
        m[s]++;
    }
}

int c;
void solution()
{
    for (auto e : m)
    {
        if(e.second == 2)
        {
            ans.push_back(e.first);
            c++;
        }
    }

    cout << c << '\n';
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << '\n';
    }
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}