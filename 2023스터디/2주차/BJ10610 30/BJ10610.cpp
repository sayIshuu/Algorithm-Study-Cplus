#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[10];
int main(void)
{
    string str;
    cin >> str;

    long long sum = 0;
    //한자리씩 탐색하면 되니 굳이 정수형태배열을 따로 안만들어도 된다!
    for (int i = 0; i < str.size(); i++)
    {
        sum += (str[i] -'0');
        arr[str[i] - '0']++;
    }
    
    if(arr[0] == 0 || (sum%3 != 0))
    {
        cout << "-1";
        return 0;
    }

    for (int i = 9; i >= 0; i--)
    {
        while (arr[i] > 0)
        {
            cout << i;
            arr[i]--;
        }
    }
    
    return 0;
}