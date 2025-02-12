#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
typedef struct{
    int execpt;
    int include;
}node;

node dfs(int parent, int x){
    if(tree[x].size() == 1 && tree[x][0] == parent)
        return {0,1};
    
    int e = 0;
    int i = 1;
    
    for(auto child : tree[x]){
        if(child == parent) continue;
        
        node temp = dfs(x,child);
        e += temp.include;
        i += min(temp.include, temp.execpt);
    }
    
    return {e,i};
}


int solution(int n, vector<vector<int>> lighthouse) {
    tree.resize(n+1);
    
    for(auto &l : lighthouse){
        tree[l[0]].push_back(l[1]);
        tree[l[1]].push_back(l[0]);
    }
    
    node temp = dfs(-1,1);
    return min(temp.include, temp.execpt);
}