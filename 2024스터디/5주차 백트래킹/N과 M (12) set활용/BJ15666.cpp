#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,m;
set<int> s;
vector<int> arr;
void input(){
    cin >> n >> m;
    int num;
     for(int i = 0; i < n; i++){
          cin >> num;
          s.insert(num);
     }
     arr.assign(s.begin(),s.end());
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

    for(int i = idx; i < arr.size(); i++){
        ans.push_back(arr[i]);
        backtracking(i);
        ans.pop_back();
    }
}

void solve()
{
    input();
    backtracking(0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}