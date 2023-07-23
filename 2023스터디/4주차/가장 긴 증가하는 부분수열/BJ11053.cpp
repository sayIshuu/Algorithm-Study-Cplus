#include <iostream>
using namespace std;

int arr[1001];
int ans[1001];

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j <= i; j++)
        {
            if(arr[j] < arr[i] && ans[j] > temp)
            {
                temp = ans[j];
            }
        }
        ans[i] = temp+1;
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[i] >= answer)
            answer = ans[i];
    }
    
    cout << answer;

    return 0;
}