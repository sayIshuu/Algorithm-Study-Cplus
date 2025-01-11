#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int ans;
vector<vector<int>> v(1001);
int main(void)
{
    cin >> n;
    //v.resize(n);
    int d,w;
    for (int i = 0; i < n; i++){
        cin >> d >> w;
        v[d].push_back(w);
    }

    priority_queue<int> pq;
    for (int i = 1000; i > 0; i--)
    {
        if(!v[i].empty())
            for (int j = 0; j < v[i].size(); j++)
                pq.push(v[i][j]);
        
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    
    return 0;
}