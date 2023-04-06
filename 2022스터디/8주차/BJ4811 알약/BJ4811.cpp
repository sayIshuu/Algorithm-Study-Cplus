#include <iostream>
using namespace std;


int main(void)
{
    int n;  cin >> n;
    int n2 = n*2;
    long long qnswk = 1;

    int qnsah = 1;

    for(int i = 0; i < n; i++)
    {
        qnswk *= n2-i;
        qnswk /= 2;
        qnsah *= i+1;
        i++;
        qnswk *= n2 -i;
    }

}