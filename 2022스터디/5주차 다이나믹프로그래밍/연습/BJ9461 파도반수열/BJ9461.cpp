//BJ9461 파도반수열 실3 다이나믹프로그래밍
#include <iostream>
using namespace std;

int main(void)
{
    int t;  cin >> t;
    long long p[101] = {0,1,1,1,2,2,};    //인덱스는 100번까지

    for (int i = 6; i < 101; i++)
    {
        p[i] = p[i-1]+p[i-5];
    }

    while(t--)
    {
        int n; cin >> n;
        cout << p[n] << endl;
    }

    return 0;
}