#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 101

int n,*maxSum;
int D[MAXN][MAXN];

int main(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i)
        for (int j=1;j<=i;++j)
            cin>>D[i][j];
    maxSum=D[n];
    for (int i = n-1; i >=1; --i)
        for (int j = 1; j <=i; j++)
            maxSum[j]=max(maxSum[j],maxSum[j+1])+D[i][j];
        
    cout<<maxSum[1]<<endl;
    return 0;
}