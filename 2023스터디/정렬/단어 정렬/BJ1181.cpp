#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	else 
		return a.length() < b.length();
}

void input()
{
    int n; cin >> n;
    string arr[n] = {};
    for (int i = 0; i < n; i++)
    {
        string a = "";
        cin >> a;
        bool c = true;
        for (int j = 0; j < i; j++)
        {
            if(a == arr[j])
            {
                c = false;
                break;
            }
        }
        if(c)
        {
            arr[i] = a;
        }
        else{
            i--;
            n--;
        }
    }
    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}

void solve()
{
    input();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}