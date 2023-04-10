//실4 괄호 알고리즘 분류 문자열 23.04.10    실3 470->478
#include <iostream>
#include <string>
using namespace std;

//문제아이디어 : 스택 자료구조.
//굳이 vector 안만들어도 되는게 (랑 )만 나와서
//마지막에 count가 0인지 아닌지만 보자.
string str;
int main(void)
{
    int n; cin >> n;
    //getline()사용 이전에 cin이 있으면 stdin 버퍼에 남은 \n을 cin.ignore()을 이용해 지워 준다.
    cin.ignore();
    while (n--)
    {
        int stack = 0;
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == '(')
                stack++;
            else if(str[i] == ')')
                stack--;
            //if문 위치.. 반복문의 앞에 위치시켰다가 마지막에 stack<0되는 경우 빠뜨림.
            if(stack < 0)
            {
                cout << "NO" << '\n';
                break;
            }
        }
        if(stack == 0)
            cout << "YES" << '\n';
        else if (stack > 0)
            cout << "NO" << '\n';
    }
    

    return 0;
}