#include <iostream>
#define MOD 15746
using namespace std;

int arr[1000001] = {1,2,3,5,}; //���� int �迭�� 1�����ϸ� �ȴ�.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 4; i <= n; i++)
        arr[i] = (arr[i-1] + arr[i-2]) % MOD;
    cout << arr[n-1];
    return 0;
}