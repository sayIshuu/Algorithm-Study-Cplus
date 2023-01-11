//BJ4673 셀프 넘버 실4 언타멘토링 2주차
#include <iostream>
using namespace std;

/*  문제추상화
구조체배열.
각 칸의 데이터. 채워졌냐, 다음숫자를 생성했냐
채워졌냐 중 젤 큰 수와 다음숫자를 생성했냐중 젤 큰 수 사이에
안채워진 수? = > 셀프넘버
셀프넘버 출력하고 다음숫자 생성하고 다음숫자 생성했냐 초기화하고
반복 끝.
*/

typedef struct index
{
    int num;                    // 1~10000사이의 수
    bool isFill = false;        // 채워졌냐. 생성되었느냐.
    bool isProduct = false;     // 다음 숫자를 생성했느냐
}Index;



int main(void)
{
    Index arr[10000];

    arr[1] = {1, true, false};  // 1은 이미 셀프 넘버고 기준이 되기에 미리 설정
    cout << arr[1].num << endl;
    int MAXnumberFill = 1;      // 채워진 숫자 중 젤 큰 수
    int MAXnumberProduct = 0;   // 다음 수를 이미 생성한 수 중 젤 큰 수

    // Index 숫자 매칭
    for (int i = 2; i < 10000; i++)
    {
        arr[i].num = i;
    }
    
    int a = 1;
    while (a < 10000)   // 반복문 두개지만 계산은 하나도는만큼만.
    {
        int MNF = MAXnumberFill;
        int MNP = MAXnumberProduct; // 어거지긴한데 아래 반복문 와중에 변수변경이 있어서 접근제한을 한번 걸어놓음
        for (a = MNP + 1; a <= MNF; a++)
        {
            if(!arr[a].isFill)
            {
                cout << arr[a].num << endl;     // (1)셀프넘버 출력
                arr[a].isFill = true;
            }

            // (2)다음 수 생성해서 채워넣기
            int next = arr[a].num + (arr[a].num/1000) + (arr[a].num%1000)/100 + (arr[a].num%100)/10 + (arr[a].num%10)/1;
            // (3)상태들 최신화
            arr[a].isProduct = true;
            if(next<10000)  // 쓰레기값 출력 방지
            {
                arr[next].isFill = true;
                MAXnumberFill = next;
                MAXnumberProduct = a;
            }
        }
    }

    return 0;
}




