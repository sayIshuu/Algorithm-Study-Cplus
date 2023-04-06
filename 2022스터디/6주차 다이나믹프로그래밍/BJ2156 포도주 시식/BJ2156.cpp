//BJ2156 �����ֽý� ��1 ��Ÿ���丵6���� ���̳��� ���α׷���
#include <iostream>
#include <algorithm>
using namespace std;

// Ǯ�� 1)
// 2^n���� Ǯ��.. �ϳ� �ٰų� �ΰ� �ٰų�. �ٵ� ���� ������ �ȵǰ� ����.
// �ؼ� ��� �� ��

// Ǯ�� 2)
// ����° �ε������� �ʱ⼳���س���.
// �ϳ���, �ΰ���, �������� ���� �� �ִ� �ִ�ġ�߿��� ��ū�� ������.
// �����°� �ϳ������� (�ΰ���,�������߿� ū��)�� ���� ����.
// ����ĭ���� �ϳ����� �ִ밪�� (�ΰ���,�������߿� ū��)�� ����
// �ٴ���ĭ���� �ΰ����� �ִ밪�� ������ �ִ밪���� ��ȯ�Ǿ�����....(�׳� �ϳ����̶�, �ΰ����������߿� ū�� �Ѵ� ���� �����س��� if������ ����)
// ������ �ٵ����� ��, ��,�ϳ����߿��� �ִ��� ������ ����.


int main(void)
{
    int n; cin >> n;

    int cups[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cups[i];
    }
    
    //�ٷ� ������ ��������
    int temp_1[n];
    //�ι�°�� ����°���̶� ���������߿� ū��
    int temp_23[n];
    //�ᱹ ū��
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


    // �Ͽ���..���س༮.. �̷��� �˾Ƽ� ó���϶������� ��
    if(n==1)
        cout << solution[0];
    else if(n>=2)
        cout << max(solution[n-1],solution[n-2]);

    return 0;
}