#include <iostream>
using namespace std;

int arr[8];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    
    bool isAscending = true;
    bool isDescending = true;

    for (int i = 1; i < 8; i++)
    {
        if(arr[i] > arr[i-1])
            isDescending = false;
        else
            isAscending = false;
    }
    
    if(isAscending)
        cout << "ascending";
    else if(isDescending)
        cout << "descending";
    else
        cout << "mixed";

    return 0;
}