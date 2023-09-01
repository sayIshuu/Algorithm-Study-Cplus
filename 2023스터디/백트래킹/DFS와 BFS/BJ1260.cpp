#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int n,m,v;
bool check[1001];
vector<vector<int>> l(1001);

void input()
{
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        l[a].push_back(b);
        l[b].push_back(a);
    }
    for (int i = 0; i < l.size(); i++)
    {
        sort(l[i].begin(), l[i].end());
    }
}

deque<int> d;
void dfs()
{
    int b = d.back();
    for (int i = 0; i < l[b].size(); i++)
    {
        if(check[l[b][i]])
            continue;
        
        d.push_back(l[b][i]);
        check[l[b][i]] = true;
        cout << l[b][i] << ' ';
        dfs();
        d.pop_back();
    }
}

queue<int> q;
void bfs()
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < l[x].size(); i++)
        {
            if(!check[l[x][i]])
            {
                q.push(l[x][i]);
                cout << l[x][i] << ' ';
                check[l[x][i]] = true;
            }
        }
    }
}


void solve()
{
    input();
    

    d.push_back(v);
    check[v] = true;
    cout << v << ' ';
    dfs();

    for (int i = 0; i < 1001; i++)
    {
        check[i] = false;
    }
    
    cout << endl;
    cout << v << ' ';
    check[v] = true;
    q.push(v);
    bfs();

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}