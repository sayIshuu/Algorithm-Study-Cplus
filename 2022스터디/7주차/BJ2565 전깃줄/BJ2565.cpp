//BJ2565 ������ ��5 23.02.22
//A���� ������������, B���� ������ �� �۴�? pop�ϰ� count++
//�ٽ� ÷���� �о�. ������ �ݺ�
//A,B�� ���������̸� count�� ��.

//�ݷ��־ �������� �����ؼ� �������°͵� �ؼ� ���� ��.
//�� ���ľ��ϳ�.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct node
{
    int A;
    int B;
}NODE;


vector<NODE> arr;

void sortArr()
{
    for(int i = 0; i < (arr.size())-1; i++)
    {
        NODE temp;
        if(arr[i].A > arr[i+1].A)
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i=0;
            continue;
        }
    }
}
/*
void sortDownArr()
{
    for(int i = 0; i < (downArr.size())-1; i++)
    {
        NODE temp;
        if(downArr[i].A < downArr[i+1].A)
        {
            temp = downArr[i];
            downArr[i] = downArr[i+1];
            downArr[i+1] = temp;
            i=0;
            continue;
        }
    }
}
*/

int main(void)
{
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        NODE temp;
        cin >> temp.A;
        cin >> temp.B;
        arr.push_back(temp);
    }
    vector<NODE> downArr(arr);

    int count1 = 0;

    int i = 0;
    sortArr();
    while(i < (arr.size())-1)
    {           
        if(arr[i].B > arr[i+1].B)
        {
            arr.erase(arr.begin()+i);
            count1++;
            i=0;
            continue;
        }
        i++;
    }

    int count2 = 0;
    int d = 0;
    for(int i = 0; i < (downArr.size())-1; i++)
    {
        NODE temp;
        if(downArr[i].A < downArr[i+1].A)
        {
            temp = downArr[i];
            downArr[i] = downArr[i+1];
            downArr[i+1] = temp;
            i=0;
            continue;
        }
    }
    while(d < (downArr.size())-1)
    {           
        if(downArr[d].B < downArr[d+1].B)
        {
            downArr.erase(downArr.begin()+d);
            count2++;
            d=0;
            continue;
        }
        d++;
    }

    
    cout << min(count1,count2);
    return 0;
}