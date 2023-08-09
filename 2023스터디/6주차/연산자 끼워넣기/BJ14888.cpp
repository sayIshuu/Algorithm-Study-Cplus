#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;

int n;
long long ma = MAX * -1;
long long mi = MAX;
long long arr[11];
bool check[11];
vector<char> opt;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int t; cin >> t;
    while (t--)
        opt.push_back('+');
    cin >> t;
    while (t--)
        opt.push_back('-');
    cin >> t;
    while (t--)
        opt.push_back('*');
    cin >> t;
    while (t--)
        opt.push_back('/');
}

void back(int i_arr, long long sum) //인자는 이제부터 처리할 인덱스
{
    if(i_arr == n)
    {
        ma = max(ma, sum);
        mi = min(mi, sum);
        return;
    }

    for (int i = 0; i < opt.size(); i++)
    {
        long long tempsum = sum;
        if(check[i] == false)
        {
            if(opt[i] == '+')
                tempsum += arr[i_arr];
            else if(opt[i] == '-')
                tempsum -= arr[i_arr];
            else if(opt[i] == '*')
                tempsum *= arr[i_arr];
            else
                tempsum /= arr[i_arr];

            check[i] = true;
        }
        else
            continue;
        back(i_arr+1, tempsum);

        check[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    back(1, arr[0]);

    cout << ma << '\n' << mi;
    return 0;
}