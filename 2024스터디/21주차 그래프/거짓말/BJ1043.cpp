#include <iostream>
#include <vector>
using namespace std;

int n, m;
int numOfKnows;

typedef struct{
    int myRoot;
    bool know;
}node;

node arr[52];

//��Ʈ�� ����
int getRoot(int x){
    //�� ��Ʈ�� ����?
    if(arr[x].myRoot == x)
        return x;
    //�ƴϴ�? �� ��Ʈ�� �� �θ��� ��Ʈ��~
    return arr[x].myRoot = getRoot(arr[x].myRoot);
}

void unionRoot(int a, int b){
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);

    //�Ѹ��� �˸� �� �ƴ� ��.
    if(aRoot>bRoot){
        arr[bRoot].myRoot = aRoot;
        arr[aRoot].know = (arr[aRoot].know || arr[bRoot].know);
    }
    else{
        arr[aRoot].myRoot = bRoot;
        arr[bRoot].know = (arr[bRoot].know || arr[aRoot].know);
    }
}


int main(void)
{
		cin >> n >> m;
    
    for(int i=1; i<n+1; i++)
        //�ϴ� �ڱ� �ڽ��� ��Ʈ
        arr[i].myRoot = i;
        
    cin >> numOfKnows;
    for (int i = 0; i < numOfKnows; i++){
        int a; cin >> a;
        arr[a].know = true;
    }
    
    vector<int> ans;
    for (int i = 0; i < m; i++){
        //������ �ѹ��� ��Ʈ ���� �Ƿ���..? �ٵ� �׳� �ΰ��� ��ħ ��
        int members; cin >> members;
        int temp = 0;
        arr[0] = {0, false};
        while (members--){
            int a; cin >> a;
            unionRoot(a, temp);
            temp = a;
        }
        ans.push_back(temp);
    }
    
    int answer = 0;
    for(auto var : ans){
        if(!arr[getRoot(var)].know)
            answer++;
    }

    cout << answer;

    return 0;
}