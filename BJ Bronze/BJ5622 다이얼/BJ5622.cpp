// 다이얼 브2
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str = "";
    getline(cin,str);

    long sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'Z'){
            sum += 10;
            continue;
        }
        int a = str[i] - 65;
        if(a>=18)
            a--;
        sum += a/3 +3;
    }
    cout << sum;
    return 0;
}