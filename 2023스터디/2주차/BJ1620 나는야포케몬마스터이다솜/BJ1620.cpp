#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,string> um;

    int n,m; cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string name; cin >> name;
        string num = to_string(i);
        um[name] = num;
        um[num] = name;
    }

    for (int i = 0; i < m; i++)
    {
        string p; cin >> p;
        auto iter = um.find(p);
        cout << iter->second << '\n';
    }
    
    return 0;
}