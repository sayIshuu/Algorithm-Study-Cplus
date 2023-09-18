#include <iostream>
using namespace std;

bool check[42];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    for (int i = 0; i < 10; i++)
    {
        cin >> a;
        check[a % 42] = true;
    }

    int cnt = 0;
    for (int i = 0; i < 42; i++)
    {
        if (check[i])
            cnt++;
    }
    
    cout << cnt << "\n";
    
    return 0;
}