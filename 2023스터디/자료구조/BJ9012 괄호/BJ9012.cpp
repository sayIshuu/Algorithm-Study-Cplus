#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n; cin >> n;

    
    while (n--)
    {
        int stack = 0;
        string str = "";
        cin >> str;
        int check = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
                stack++;
            else if(str[i] == ')')
            {
                if (stack < 0)
                {
                    cout << "NO" << '\n';
                    check = 1;
                    break;
                }
                else
                    stack--;
            }
        }
        
        if(stack==0 && check == 0)
        {
            cout << "YES" << '\n';
        }
        else if(check == 0)
            cout << "NO" << '\n';
    }
    

    return 0;
}