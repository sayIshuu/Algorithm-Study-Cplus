//��5 �ܰ躰�� Ǯ��� �ݺ��� 23.04.07
#include <iostream>
using namespace std;
int main(void)
{
    int n; cin >> n;
    long long sol = 0; 
    for (int i = 1; i <= n; i++)
        sol += i;
    cout << sol;
    return 0;
}