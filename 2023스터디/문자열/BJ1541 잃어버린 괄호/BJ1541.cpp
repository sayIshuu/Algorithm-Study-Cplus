//실2 잃어버린 괄호 알고리즘 분류 문자열    23.04.10    478->487
#include <iostream>
#include <string>
using namespace std;

//첫 '-' 이후로 그냥 다빼버림.
//-가 등장 전 후 나누는 bool형 트리거 필요.
//split 안쓰고 string의 push_back으로 숫자하나씩 털고 초기화하는 방식사용.

int main(void)
{
    bool beforeminus = true;

    string str = "";
    getline(cin, str);

    int sum = 0;

    string number = "";
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+' || str[i] == '-')
        {
            if(beforeminus)
                sum += stoi(number);
            else
                sum -= stoi(number);
            number = "";
            if(str[i] == '-')
                beforeminus = false;
            continue;
        }
        number.push_back(str[i]);
    }
    if(beforeminus)
        sum += stoi(number);
    else
        sum -= stoi(number);
    cout << sum;

    return 0;
}