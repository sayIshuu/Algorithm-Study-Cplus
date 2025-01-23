#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
int t, n, m;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        s.clear();
        cin >> n;
        int num = 0;
        for (int i = 0; i < n; i++){
            cin >> num;
            s.insert(num);
        }
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> num;
            if(s.count(num) == 1)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }
    
    return 0;
}