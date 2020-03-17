#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

int main() {

    int N,M;    //N层楼，M个鸡蛋
    cin>>N>>M;

    int egg[110][110] = { 0 };

    for (int i = 1; i <= N; ++i)
    {
        egg[1][i] = i;
    }

    for (int i = 1; i <= M; ++i)
    {
        egg[i][1] = 1;
    }
    
    for (int i = 2; i <= M; ++i) {
        for (int j = 2; j <= N; ++j)
        {
            egg[i][j] = INF;

            for (int k = 1; k <= j; ++k)
            {
                egg[i][j] = min(egg[i][j],max(egg[i][j-k],egg[i-1][k-1])+1);
            }
            
        }
        
    }
    cout<<egg[M][N]<<endl;
    return 0;
}