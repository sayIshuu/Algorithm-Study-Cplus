#include <iostream>
using namespace std;

int arr[9];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int sum = 0;
	for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int b = 0; b < 8; b++)
    {
        int tempsum = 0;
        tempsum += arr[b];
        for (int c = b+1; c < 9; c++)
        {
            tempsum += arr[c];
            if((sum - tempsum) == 100)
            {
                for (int i = 0; i < 9; i++)
                {
                    if(i != b && i != c)
                        cout << arr[i] << '\n';
                }
                return 0;
            }
            tempsum = arr[b];
        }
    }
    return 0;
}