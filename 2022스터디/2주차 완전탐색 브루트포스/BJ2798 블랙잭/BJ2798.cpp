#include <iostream>
using namespace std;

//�������̵�� ���Ʈ����. 
//ù��°������� �ι�°���� ��� ������������
//�ι�°���� �ϳ� �ø��� ������ ������
//���� 3��..�μ��� a�� ����ǰ�

int arr[101];

int main(void)
{
    int n; cin >> n;
    int m; cin >> m;

    for (int a = 0; a < n; a++)
    {
        cin >> arr[a];
    }
    
    int sum = 0;
    int ans = 0;
    for (int a = 0; a < n-2; a++)
    {
        sum = arr[a];
        if(sum > m) continue;
        for (int b = a+1; b < n-1; b++)
        {
            sum = arr[a];
            sum += arr[b];
            if(sum > m) continue;
            for (int c = b+1; c < n; c++)
            {
                sum = arr[a]+arr[b];
                sum += arr[c];
                if(sum > m) continue;
                if(sum == m)
                {
                    cout << sum;
                    return 0;
                }
                if(sum > ans) ans = sum;
            }            
        }    
    }
    
    cout << ans << endl;
    return 0;
}