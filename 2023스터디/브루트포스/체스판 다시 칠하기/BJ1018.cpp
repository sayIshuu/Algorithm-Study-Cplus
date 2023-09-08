#include <iostream>
#include <algorithm>
using namespace std;

char arr[51][51];
int n,m;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int sum = 1000000;
void solution()
{
    for (int a = 0; a < n-7; a++)
    {
        for(int b = 0; b < m-7; b++)
        {
            int count1 = 0; int count2 = 0;
            char w = 'W';
            for (int i = a; i < a+8; i++)
            {
                for (int j = b; j < b+8; j++)
                {
                    if(arr[i][j] != w)
                        count1++;
                    
                    if(w == 'W')
                        w = 'B';
                    else
                        w = 'W';
                }  
                if(w == 'W')
                    w = 'B';
                else
                    w = 'W';
            }

            w = 'B';
            for (int i = a; i < a+8; i++)
            {
                for (int j = b; j < b+8; j++)
                {
                    if(arr[i][j] != w)
                        count2++;
                    
                    if(w == 'W')
                        w = 'B';
                    else
                        w = 'W';
                }
                if(w == 'W')
                    w = 'B';
                else
                    w = 'W';
            }

            if(sum > min(count1,count2))
                sum = min(count1,count2);
        }
    }
    cout << sum;
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}