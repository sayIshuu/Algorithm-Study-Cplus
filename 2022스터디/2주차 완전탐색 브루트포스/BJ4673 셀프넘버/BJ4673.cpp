//BJ4673 ���� �ѹ� ��5 ��Ÿ���丵 2����
#include <iostream>
using namespace std;

/*  �����߻�ȭ
����ü�迭.
�� ĭ�� ������. ä������, �������ڸ� �����߳�
ä������ �� �� ū ���� �������ڸ� �����߳��� �� ū �� ���̿�
��ä���� ��? = > �����ѹ�
�����ѹ� ����ϰ� �������� �����ϰ� �������� �����߳� �ʱ�ȭ�ϰ�
�ݺ� ��.
*/

typedef struct index
{
    int num;                    // 1~10000������ ��
    bool isFill = false;        // ä������. �����Ǿ�����.
    bool isProduct = false;     // ���� ���ڸ� �����ߴ���
}Index;



int main(void)
{
    Index arr[10000];

    arr[1] = {1, true, false};  // 1�� �̹� ���� �ѹ��� ������ �Ǳ⿡ �̸� ����
    cout << arr[1].num << endl;
    int MAXnumberFill = 1;      // ä���� ���� �� �� ū ��
    int MAXnumberProduct = 0;   // ���� ���� �̹� ������ �� �� �� ū ��

    // Index ���� ��Ī
    for (int i = 2; i < 10000; i++)
    {
        arr[i].num = i;
    }
    
    int a = 1;
    while (a < 10000)   // �ݺ��� �ΰ����� ����� �ϳ����¸�ŭ��.
    {
        int MNF = MAXnumberFill;
        int MNP = MAXnumberProduct; // ��������ѵ� �Ʒ� �ݺ��� ���߿� ���������� �־ ���������� �ѹ� �ɾ����
        for (a = MNP + 1; a <= MNF; a++)
        {
            if(!arr[a].isFill)
            {
                cout << arr[a].num << endl;     // (1)�����ѹ� ���
                arr[a].isFill = true;
            }

            // (2)���� �� �����ؼ� ä���ֱ�
            int next = arr[a].num + (arr[a].num/1000) + (arr[a].num%1000)/100 + (arr[a].num%100)/10 + (arr[a].num%10)/1;
            // (3)���µ� �ֽ�ȭ
            arr[a].isProduct = true;
            if(next<10000)  // �����Ⱚ ��� ����
            {
                arr[next].isFill = true;
                MAXnumberFill = next;
                MAXnumberProduct = a;
            }
        }
    }

    return 0;
}




