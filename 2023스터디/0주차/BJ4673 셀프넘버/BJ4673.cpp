#include <iostream>
using namespace std;

int arr[10001];

int f(int a)
{
    int temp = a;
    int sum = a;
    
    sum += (temp/1000);
    temp %= 1000;
    sum += (temp/100);
    temp %= 100;
    sum += (temp/10);
    temp %= 10;
    sum += temp;

    return sum;
}

int main(void)
{
    for (int i = 1; i < 9999; i++)
    {
        if(f(i) <= 10000)
            arr[f(i)] = 1;
    }
    
    for (int i = 1; i < 10000; i++)
    {
        if(arr[i] == 0)
            cout << i << '\n';
    }
    
    return 0;
}