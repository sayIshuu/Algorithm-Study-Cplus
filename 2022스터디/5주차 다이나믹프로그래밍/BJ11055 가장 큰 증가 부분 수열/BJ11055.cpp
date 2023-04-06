//BJ11055 가장 큰 증가 부분 수열 실2 언타멘토링5주차 다이나믹프로그래밍
#include <iostream>
using namespace std;

// 비단 경우의 수가 아닌 같은 함수로 쌓아가는 문제? => DP로 푼다.
// 그래서 어떻게 쌓여가는지를 찾아야함. 이게 점화식으로도 이어지고 등등.

int arr[1001];
int ans[1001];

int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ans[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j <= i; j++)
        {
            if(arr[j] < arr[i] && ans[j] > temp)
            {
                temp = ans[j];
            }
        }
        ans[i] += temp;
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if(ans[i] >= answer)
        {
            answer = ans[i];
        }
    }
    
    cout << answer << endl;

    return 0;
}














/* 스택을 이용했던 풀이.. 반례발생.
int arr[1001];

long ans = 0;

vector<int> stack;
vector<int> ansStack;

void updateAnswer()
{
    int count = 0;
    for (int i = 0; i < stack.size(); i++)
    {
        count += stack[i];
    }
    if(ans < count)
    {
        ans = count;
        ansStack.clear();
        ansStack.assign(stack.begin(), stack.end());
    }       
}


int main(void)
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    

    for (int i = 0; i < n; i++)
    {
        if(stack.empty())
        {
            stack.push_back(arr[i]);
            updateAnswer();
        }
        else
        {
            if(arr[i] > ansStack.back())
            {
                stack.clear();
                stack.assign(ansStack.begin(), ansStack.end());
            }
            while (!stack.empty() && stack.back() >= arr[i])
            {
                stack.pop_back();
            }
            stack.push_back(arr[i]);
            updateAnswer();
        }        
    }
    
    
    cout << ans << endl;

    return 0;
}
*/