//실5 소트인사이드 알고리즘 분류 문자열 492->498
#include <iostream>
#include <string>
using namespace std;

int numbers[10] = {0,};
int main(void)
{
    string str = "";
    getline(cin,str);
    for (int i = 0; i < str.length(); i++)
    {
        numbers[(str[i] - '0')]++;
    }
    
    string ans = "";
    for (int i = 9; i >= 0; i--)
    {
        for (int j = numbers[i]; j>0; j--)
        {
            ans.push_back(i + '0');
        }    
    }
    cout << ans;

    return 0;
}