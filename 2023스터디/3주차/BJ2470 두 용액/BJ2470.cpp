#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[100001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    int f = 0;  int e = n-1;
    int min = 2000000000;
    int ansf = 0;   int anse = 0;

    //Ž���� ����Ʈ�� ���Ʈ������ �ƴ϶�, �����͸� �ű�� ������ ������ �մٴ���
    //���� ������, ����Ŀ� ���� f,e�������� �� �ŰܾߵǴ����� �ٸ���

    while(f<e)
    {
        int sum = arr[f]+arr[e];
        if(abs(sum) < min)
        {
            min = abs(sum);
            ansf = arr[f];
            anse = arr[e];
        }

        if(sum > 0)
            e--;
        else
            f++;
    }

    cout << ansf << ' ' << anse;
    
    return 0;
}