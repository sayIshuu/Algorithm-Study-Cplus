//BJ2156 포도주시식 실1 언타멘토링6주차 다이나믹 프로그래밍
#include <iostream>
#include <algorithm>
using namespace std;

// 풀이 1)
// 2^n으로 풀지.. 하나 뛰거나 두개 뛰거나. 근데 세개 연속은 안되게 조건.
// 해서 모든 값 비교

// 풀이 2)
// 세번째 인덱스까진 초기설정해놓음.
// 하나전, 두개전, 세개전이 가질 수 있는 최대치중에서 젤큰거 가져옴.
// 가져온게 하나전꺼면 (두개전,세개전중에 큰거)도 따로 저장.
// 다음칸에서 하나전의 최대값은 (두개전,세개전중에 큰거)로 보임
// 다다음칸에서 두개전의 최대값은 본래의 최대값으로 전환되어있음....(그냥 하나전이랑, 두개전세개전중에 큰거 둘다 따로 저장해놓고 if문으로 제어)
// 끝까지 다돌았을 때, 끝,하나전중에서 최댓값을 답으로 제출.


int main(void)
{
    int n; cin >> n;

    int cups[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cups[i];
    }
    
    //바로 전꺼랑 더해진거
    int temp_1[n];
    //두번째전 세번째전이랑 더해진거중에 큰거
    int temp_23[n];
    //결국 큰거
    int solution[n];


    temp_1[0] = cups[0];
    temp_23[0] = cups[0];
    solution[0] = cups[0];

    if(n>1)
    {
        temp_1[1] = temp_23[0] + cups[1];
        temp_23[1] = max(cups[0],cups[1]);
        solution[1] = max(temp_1[1], temp_23[1]);
    }

    if(n>2)
    {
        temp_1[2] = temp_23[1] + cups[2];
        temp_23[2] = solution[0] + cups[2];
        solution[2] = max(temp_1[2], temp_23[2]);
    }

    if (n>3)
    {
        for (int i = 3; i < n; i++)
        {
            temp_1[i] = temp_23[i-1] + cups[i];
            temp_23[i] = max(solution[i-2],solution[i-3]) + cups[i];
            solution[i] = max(temp_1[i], temp_23[i]);
        }  
    }


    // 하여간..백준녀석.. 이런건 알아서 처리하란말이지 ㅎ
    if(n==1)
        cout << solution[0];
    else if(n>=2)
        cout << max(solution[n-1],solution[n-2]);

    return 0;
}