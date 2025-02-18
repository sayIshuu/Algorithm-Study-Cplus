#include <iostream>
using namespace std;

int main(void)
{
    int num; cin >> num;
    int mak = 64;
    int sum = 0;
    int ans = 0;

    while(sum != num){
        if(sum+mak <= num){
            sum += mak;
            ans++;
        }
        //나누기 2, 곱하기 2를 효율적으로하는 시프트연산
        mak >>= 1;
    }

    cout << ans;
    return 0;
}