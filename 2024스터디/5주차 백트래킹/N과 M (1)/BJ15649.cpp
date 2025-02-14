#include <iostream>
#include <vector>
using namespace std;

int n,m;
void input(){
    cin >> n >> m;
}

vector<int> ans;
//중복 요소 없어서 방문체크
bool visited[9];
void backtracking(){
    if(ans.size() == m)
    {
        for(int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        ans.push_back(i);
        backtracking();
        visited[i] = false;
        ans.pop_back();
    }
}

void solve()
{
    input();
    backtracking();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}