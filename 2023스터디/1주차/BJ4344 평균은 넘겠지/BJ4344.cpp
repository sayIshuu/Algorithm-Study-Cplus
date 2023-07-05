#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int c; cin >> c;

    cout << fixed;
    cout.precision(3);

    while (c--)
    {
        int n; cin >> n;

        long sum = 0;
        int arr[1001] = {};
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        double avg = (double)sum / (double)n;


        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] > avg)
                num++;
        }
        
        double sol = (double)num / (double)n;
        cout << sol*100 << "%" << '\n';
        
    }
    
    return 0;
}