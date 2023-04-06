//BJ10951 A+B -4 브5
#include <iostream>
using namespace std;

int main(void)
{
    //EOF(End of File): 파일의 끝, 더 이상 읽을 데이터가 없다
    while (true)
    {
        int a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        cout << a+b << '\n';
    }
    
    return 0;
}