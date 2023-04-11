//브2 OX퀴즈 알고리즘 분류 문자열   23.04.11    실3 487->492
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n; cin >> n;
    cin.ignore();
    while (n--)
    {
        string str = "";
        getline(cin,str);
        int count = 1;
        int sum = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'O')
            {
                sum += count;
                count++;
            }
            else if(str[i] == 'X')
                count = 1;
        }
        cout << sum << '\n';
    }
    
    return 0;
}