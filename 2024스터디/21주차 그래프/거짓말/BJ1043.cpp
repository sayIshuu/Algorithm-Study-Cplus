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

//루트만 빼와
int getRoot(int x){
    //내 루트가 나다?
    if(arr[x].myRoot == x)
        return x;
    //아니다? 내 루트는 내 부모의 루트다~
    return arr[x].myRoot = getRoot(arr[x].myRoot);
}

void unionRoot(int a, int b){
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);

    //뿌리가 알면 다 아는 것.
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
        //일단 자기 자신이 루트
        arr[i].myRoot = i;
        
    cin >> numOfKnows;
    for (int i = 0; i < numOfKnows; i++){
        int a; cin >> a;
        arr[a].know = true;
    }
    
    vector<int> ans;
    for (int i = 0; i < m; i++){
        //여러개 한번에 루트 통합 되려나..? 근데 그냥 두개씩 합침 ㅎ
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