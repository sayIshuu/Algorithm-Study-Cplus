#include <iostream>
#include <vector>
using namespace std;

int n,m;
void input(){
    cin >> n >> m;
}

vector<int> ans;
void backtracking(int idx){
    if(ans.size() == m)
    {
        for(int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = idx; i <= n; i++){
        ans.push_back(i);
        backtracking(i);
        ans.pop_back();
    }
}

void solve()
{
    input();
    backtracking(1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}