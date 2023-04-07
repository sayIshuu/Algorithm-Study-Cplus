//브3 단계별로 풀어보기 1차원배열
#include <iostream>
using namespace std;
int main(void)
{
    int sol = 0; int count = 0;
    for (int i = 0; i < 9; i++)
    {
        int a;  cin >> a;
        if(a > sol)
        {
            sol = a;
            count = i+1;
        }
    }
    cout << sol << '\n' << count;
    return 0;
}