//BJ11055 ���� ū ���� �κ� ���� ��2 ��Ÿ���丵5���� ���̳������α׷���
#include <iostream>
using namespace std;

// ��� ����� ���� �ƴ� ���� �Լ��� �׾ư��� ����? => DP�� Ǭ��.
// �׷��� ��� �׿��������� ã�ƾ���. �̰� ��ȭ�����ε� �̾����� ���.

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














/* ������ �̿��ߴ� Ǯ��.. �ݷʹ߻�.
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