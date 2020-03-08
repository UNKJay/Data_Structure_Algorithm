#include<iostream>
#include<algorithm>
using namespace std;

int N;
int queenPos[100];

void NQeen(int k);

int main(){
    cin>>N;
    NQeen(0);
    return 0;
}

void NQeen(int k){
    if (k==N){
        for (int i = 0; i < N; ++i)
            cout<<queenPos[i]+1<<' ';
        cout<<endl;
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        int j;
        for (j = 0; j < k; ++j)
        {
            if (queenPos[j]==i||abs(queenPos[j]-i)==abs(j-k))
                break;
        }
        if (j==k){
            queenPos[k]=i;
            NQeen(k+1);
        }
    }
}
