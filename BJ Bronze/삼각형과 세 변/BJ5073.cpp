#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);

        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;

        if(arr[0]+arr[1] <= arr[2])
        {
            cout << "Invalid\n";
            continue;
        }

        if (arr[0] == arr[1] && arr[1] == arr[2])
            cout << "Equilateral\n";
        else if (arr[0] == arr[1] || arr[1] == arr[2])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }

    return 0;
}