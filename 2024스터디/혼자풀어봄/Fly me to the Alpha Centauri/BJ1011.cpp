#include <iostream>
using namespace std;

int t;
int main(void)
{
    cin >> t;
    while(t--){
        int ans = 0;
        int s,e;
        cin >> s >> e;

        int l = e-s;
        int token = 1;

        while(true){
            if(l > token * 2){
                l -= token*2;
                token++;
                ans += 2;
            }
            else if(l <= token*2 && l > token){
                ans += 2;
                cout << ans << '\n';
                break;
            }
            else if(l <= token){
                ans++;
                cout << ans << '\n';
                break;
            }
        }
    }

    return 0;
}