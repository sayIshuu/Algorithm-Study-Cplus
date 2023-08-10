#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long arr[5001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    long long min = 3000000000;
    int ansf = 0;   int anse = 0;   int ansm = 0;

    //Ž���� ����Ʈ�� ���Ʈ������ �ƴ϶�, �����͸� �ű�� ������ ������ �մٴ���
    //���� ������, ����Ŀ� ���� f,e�������� �� �ŰܾߵǴ����� �ٸ���
    
    for (int f = 0; f < n-1; f++)
    {
        int m = f+1; int e = n-1;
        while(m<e)
        {
            long long sum = arr[m]+arr[e]+arr[f];
            if(abs(sum) < min)
            {
                min = abs(sum);
                ansf = arr[f];
                anse = arr[e];
                ansm = arr[m];
            }

            if(sum > 0)
                e--;
            else
                m++;
        }
    }
    

    cout << ansf << ' ' << ansm << ' ' << anse;

    return 0;
}


//�ذ�� : �����ϳ���� ������ �ο��