#include <iostream>
#include <queue>
using namespace std;

int n, sum;
priority_queue<int> posNums;
priority_queue<int> negNums;
int zero, one;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int input = 0;
    for (int i = 0; i < n; i++){
        cin >> input;
        if(input == 1) //1은 묶이면 안된다.
            one++;
        else if(input == 0) //음수가 남았을 때 0이 있으면 지울 수 있다.
            zero++;
        else if(input > 0)
            posNums.push(input);
        else if(input < 0) //더 작은 음수가 우선순위로 나와야하므로 -로 넣어준다.
            negNums.push(-input);
    }

    while(posNums.size() > 1){
        int temp = 0;
        temp += posNums.top();
        posNums.pop();
        temp *= posNums.top();
        posNums.pop();
        sum += temp;
    }
    if(!posNums.empty())
        sum += posNums.top();
    

    while(negNums.size() > 1){
        int temp = 0;
        temp += negNums.top();
        negNums.pop();
        temp *= negNums.top();
        negNums.pop();
        sum += temp;
    }
    if(!negNums.empty() && zero == 0){
        sum -= negNums.top();
    }
    cout << sum+one;

    return 0;
}