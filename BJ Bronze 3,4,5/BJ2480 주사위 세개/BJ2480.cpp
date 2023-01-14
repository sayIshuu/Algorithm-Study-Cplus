//BJ2480 주사위 세개 브4
#include <iostream>
#include <vector>
using namespace std;

/*
문제아이디어
1~6 눈을 각각 다른 조건으로 선언하거나 세기가 어려우니까
배열의 인덱스로 조건분리를하고
값으로 카운팅을 한다.
*/

//인덱스는 n-1이므로 0번 인덱스는 안쓴단 마인드로 7개짜리 배열생성
vector<int> noon(7);

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;

    noon[a]++;
    noon[b]++;
    noon[c]++;

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        if(noon[i] == 3)
        {
            cout << 10000 + i*1000 << endl;
            break;
        }
        else if(noon[i] == 2)
        {
            cout << 1000 + i*100 << endl;
            break;
        }
        else if(noon[i] == 1)
        {
            count++;
            if(count == 3)
            {
                cout << i*100 << endl;
                break;
            }
        }
    }
    
    return 0;
}