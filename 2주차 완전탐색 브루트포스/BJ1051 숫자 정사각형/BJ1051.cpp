// BJ1051 숫자정사각형 실4 언타멘토링 2주차
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    int n,m;
    cin >> n >> m;
    
    int array[n][m];

    string arr[n];

    int solution = 1;

    // 입력받은걸 2차원배열에 하나하나 집어넣기
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
        for (int j = 0; j < m; j++)
        {
            array[i][j] = (arr[i])[j] - '0';    // 형변환 편법
        }           
    }


    /* 알고리즘 추상화
    (0,0)==(0,m) > (0,0)==(0,m-1) ...
    (1,0)==(1,m) > ...                      !!!m까지가 아니라 m-1까지이다! 신경쓴다고 하지말고 써놓거나 해결해놓고 구현 들어가자
    ...
    (n,0)==(n,m)...같은게 나온다? 뒷m값-앞m값 길이로 설정해서 확인비교반복 break;
    길이==앞n값-뒷n값 두번 체크해서 안되면 다시 반복문 돌아가고 되면 solution 초기화
    */
    int tempLength = 1;
    for (int x = 0; x < n; x++) 
    {
        for (int y = 0; y < m; y++)
        {
            for (int p = 0; p < m-y; p++)
            {
                //윗변찾는 조건문
                if(array[x][y]==array[x][m-p-1])
                {
                    //윗변의 길이
                    tempLength = m-p-y;
                    //outofbounds 방지용 조건문
                    if (x+tempLength-1 < n)
                    {
                        // 윗변의 길이랑 두 세로변의 길이가 같은지 확인, 지금 조건까지 걸러내면 정사각형인데 그 정사각형이 기존 solution보다 큰지 확인하고 solution 최신화
                        if(array[x+tempLength-1][y]==array[x][y] && array[x+tempLength-1][m-p-1]==array[x][y] && tempLength*tempLength > solution)
                        {
                            solution = tempLength*tempLength; 
                        }
                    }
                }
            }
        }   
    }   

    cout << solution << endl;    

    return 0;
}