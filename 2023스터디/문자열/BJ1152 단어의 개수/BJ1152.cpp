//브2 단어의 개수   알고리즘 분류 문자열    23.04.10    실3 466->470
#include <iostream>
#include <string>
using namespace std;

string str;
int main(void)
{
//기존 cin은 공백문자를 구분문자로 취급하는데 getline을 활용하면 한줄 통째로 받을 수 있다.
    getline(cin, str);
    int count = 0;
    if(str == " " || str == "")
    {
        cout << count;
        return 0;
    }
    for (int i = 1; i < str.length()-1; i++)
    {
        if(str[i]==' ')
            count++;
    }
    cout << count+1;

    return 0;
}