//BJ10828 ���� ��Ÿ���丵 1����
#include <iostream>
#include <string>   //C++���� ���ڿ� �ٷ�Ⱑ �����Ͽ� ȣ��
using namespace std;

// ���Ḯ��Ʈ�� �̿��� ���ñ���,,stack Ŭ���� ���ؼ� �Ҽ��� ������ �����ǵ��� ���ñ����̶�� �����Ͽ���.
typedef struct node
{
    int Data;
    node *Next; // Top�������� �Ʒ��� �������� ������ Next
}NODE;

NODE *Top;

void Push(int data)
{
    NODE *newTop = new NODE;    // ��� ��������
    newTop->Data = data;
    newTop->Next = Top;
    Top = newTop;
}

bool Empty()    // Pop()�Լ��� ����Ϸ��� ���ǻ� bool������, ����ġ������ if���� �߰��Ͽ� ������ȯ���� �����ؾ���.
{
    return (Top == NULL);
}

int Pop()
{
    if(Empty()) // C�� ���������̶� Empty()�Լ��� ���� ������� ������ �����߻�
        return -1;
    else
    {
        NODE *temp = Top;
        Top = Top->Next;

        int data = temp->Data;
        delete temp;
        return data;
    }
}

int Size()
{
    int count = 0;
    NODE *temp = Top;

    while (temp != NULL)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

int GetTop()
{
    if(Empty())
        return -1;
    else
        return Top->Data;
}

void Remove()   //Push�Ҷ� ���������ϴϱ� �����ؾ���.
{
    while (!Empty())
    {
        NODE *temp = Top;
        Top = Top->Next;
        delete temp;
    }
}


int main(void)
{
    Top = NULL;     // ���� Ŭ������ ������ ���������� ���� �ϳ�, �����ϳ��� �۾��ϴ� ������ �׳� �����Ͽ���. �Լ��鵵 �������� Ȱ��.
    
    int n;
    cin >> n;

    string str;
    while(n>0)  
    {
        cin >> str;
        
        if(str == "push")
        {
            int num; cin >> num;    // ������� �Է��� ������� ���۸�...�ߴµ� �׳� push�� �Է������� ���� �Է��ص� ����ó�����ִ���. ����
            Push(num);
        }
        else if(str == "pop")
        {
            cout << Pop() << endl;
        }
        else if(str == "size")
        {
            cout << Size() << endl;
        }
        else if(str == "empty")
        {
            if(Empty()) //Empty()�� ���� ��ȯ�̶� if������ ���� �������
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(str == "top")
        {
            cout << GetTop() << endl;        
        }

        n--;
    }

    Remove();   //���� �����ϰ� ����
    return 0;
}


// ��ɺ� �������� ���⵵�� �����ؾ��ϴ°ǰ�..? ���⵵ �������� �� �𸣰ھ��

// �ڷᱸ������� �� �ȵǾ� ���������� �����غ��Ҵ�.
// C++�� ���ڿ��̶� ��������Է��� �����Ͽ� �ٸ��� Ȱ���غ��� �Ͽ�����, 
// ���� �� ��� ������, �����Ҵ�, ����Ʈ ���� �ٸ� ���� ��ü�Ϸ��� ����� �ȳ��� ����.
// �� ������ �ٸ� ���ε� �� Ǯ������Ұ� ���� ���� ü���ϱ�����.











/*   ���ڿ� ����ġ���� �������±��� �ϳ� �����.
string str;
    while(n>0)  // C++���� ������� �Է��� �ٷ�� ����� ���۸�.
    {
        cin >> str;
        
        switch (str)
        {
        case "push":
            int num; cin >> num;
            Push(num);
            break;
        case "pop":
            cout << Pop() << endl;
            break;
        case "size":
            cout << Size() << endl;
            break;
        case "empty":
            if(Empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        case "top":
            cout << GetTop() << endl;        
        default:
            break;
        }

        n--;
    }
*/