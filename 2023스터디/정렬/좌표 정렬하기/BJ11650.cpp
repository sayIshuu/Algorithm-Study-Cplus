#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else 
		return a.first < b.first;
}

void input()
{
    int n; cin >> n;

    while (n--)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
}

void solution()
{
    sort(v.begin(), v.end(), compare);

    for(pair<int,int> p : v)
    {
        cout << p.first << ' ' << p.second << '\n';
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