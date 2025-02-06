#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> node;
// dp[v][0]: v를 선택하지 않았을 때, v를 포함하는 서브트리의 최소 정점 커버 크기
// dp[v][1]: v를 선택했을 때, v를 포함하는 서브트리의 최소 정점 커버 크기
vector<vector<int>> dp;

void dfs(int cur, int parent) {
    dp[cur][0] = 0;   // cur를 선택하지 않으면, 비용은 0부터 시작
    dp[cur][1] = 1;   // cur를 선택하면, 자기 자신 1을 포함
    // cur의 모든 자식에 대해 처리 (부모로 돌아가는 것 방지)
    for (int next : node[cur]) {
        if (next == parent) continue;
        dfs(next, cur);
        // cur를 선택하지 않는 경우: cur와 인접한 모든 노드(여기서는 자식)는 반드시 선택되어야 함
        dp[cur][0] += dp[next][1];
        // cur를 선택한 경우: 자식은 선택해도 되고, 선택하지 않아도 되나 최소값을 취함
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    node.resize(n+1);
    dp.resize(n+1, vector<int>(2, 0));
    
    // 트리의 간선 정보 입력 (노드 번호는 1번부터 n번까지, 간선은 n-1개)
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    
    // 1번 노드를 루트로 하여 DFS 수행
    dfs(1, -1);
    
    // 루트에 대해 선택하지 않은 경우와 선택한 경우 중 최소값이 전체 최소 정점 커버의 크기
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
