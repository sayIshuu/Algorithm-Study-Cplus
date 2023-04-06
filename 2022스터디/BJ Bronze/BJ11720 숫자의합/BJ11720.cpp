//BJ11720 숫자의합 브4
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    string str = "";
    cin >> str;
    //초기화 습관화 하자. 입력이 00000으로 나오면 카운트가 0이여야하는데 가비지값으로 설정되어있으면 오답나옴.
    int count = 0;

    while (n--) 
    {
        count += (str[n]-'0');
    }
    
    cout << count;

    return 0;
}