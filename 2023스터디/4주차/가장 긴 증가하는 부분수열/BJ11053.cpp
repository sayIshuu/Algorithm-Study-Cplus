#include <iostream>
#include <algorithm>
using namespace std;
//dp는 수열을 만들어 놓고 마지막 인덱스에 답이 오게끔하는게 답
//그러므로 어떻게 30에 3, 50에 4가 올수있나 고민해보아야한다.
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
    /*
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[i] >= answer)
            answer = ans[i];
    }
    */
    cout << *max_element(ans, ans+n);

    return 0;
}