//브4 파티가 끝나고 난뒤 498->501
#include <iostream>
using namespace std;

int main(void)
{
    int a, b; cin >> a >> b;

    for (int i = 0; i < 5; i++)
    {
        int k; cin >> k;
        cout << k-(a*b) << ' ';
    }
    return 0;   
}