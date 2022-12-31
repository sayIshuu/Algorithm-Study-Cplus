#include <iostream>
#include <string>   //C++에서 문자열 다루기가 복잡하여 호출
using namespace std;

// 연결리스트를 이용한 스택구현,,stack 클래스 통해서 할수도 있지만 문제의도는 스택구현이라고 생각하였다.
typedef struct node
{
    int Data;
    node *Next; // Top에서부터 아래로 내려가는 느낌의 Next
}NODE;

NODE *Top;

void Push(int data)
{
    NODE *newTop = new NODE;    // 노드 동적생성
    newTop->Data = data;
    newTop->Next = Top;
    Top = newTop;
}

bool Empty()    // Pop()함수에 사용하려고 편의상 bool리턴형, 스위치문에선 if문을 추가하여 정수반환으로 조정해야함.
{
    return (Top == NULL);
}

int Pop()
{
    if(Empty()) // C는 절차지향이라 Empty()함수가 먼저 선언되지 않으면 오류발생
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

void Remove()   //Push할때 동적생성하니까 해제해야함.
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
    Top = NULL;     // 본래 클래스로 스택을 구현하지만 파일 하나, 스택하나로 작업하는 문제라 그냥 선언하였음. 함수들도 전역공간 활용.
    
    int n;
    cin >> n;

    string str;
    while(n>0)  
    {
        cin >> str;
        
        if(str == "push")
        {
            int num; cin >> num;    // 띄워쓰기 입력이 어려워서 구글링...했는데 그냥 push랑 입력정수랑 따로 입력해도 정답처리해주더라. 왜지
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
            if(Empty()) //Empty()가 불형 반환이라 if문으로 따로 정수출력
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

    Remove();   //노드들 안전하게 해제
    return 0;
}


// 기능별 노드단위로 복잡도를 측정해야하는건가..? 복잡도 측정법을 잘 모르겠어요

// 자료구조배운지 얼마 안되어 정석적으로 구현해보았다.
// C++이 문자열이랑 띄워쓰기입력이 막막하여 다른언어를 활용해보려 하였으나, 
// 수업 때 배운 포인터, 동적할당, 리스트 등을 다른 언어로 대체하려니 기억이 안나서 포기.
// 이 문제는 다른 언어로도 다 풀어봐야할것 같음 배운거 체득하기위해.











/*   문자열 스위치문은 에러나는구나 하나 배웠다.
string str;
    while(n>0)  // C++에서 띄워쓰기 입력이 다루기 어려워 구글링.
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