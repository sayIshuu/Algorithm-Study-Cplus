#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<int> v;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        if(binary_search(v.begin(),v.end(),a))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    
    

    return 0;
}