#include <iostream>
#include <vector>
using namespace std;

int t,n;

//false¸é ¼Ò¼ö
bool isNotPrime[10001] = {true, true, false,};

vector<int> prime;

void primeCheck(){
    for (int i = 2; i < 10000; i++)
    {
        if(isNotPrime[i])
            continue;
        else{
            for (int j = i+i; j < 10000; j+=i)
                isNotPrime[j] = true;
        }
    }

    for (int i = 2; i < 10000; i++)
    {
        if(!isNotPrime[i])
            prime.push_back(i);
    }
}

void goldbah(int n)
{
    int left = 0;
    int right = prime.size()-1;

    int l,r;
    while (left <= right)
    {
        if(prime[left] + prime[right] == n){
            l = prime[left];
            r = prime[right];
            left++;
        }
        else if(prime[left] + prime[right] < n)
            left++;
        else
            right--;
    }

    cout << l << ' ' << r << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;

        goldbah(n);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    primeCheck();
    input();

    return 0;
}