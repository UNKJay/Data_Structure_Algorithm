#include<iostream>  
#include<cstring>
#include<algorithm>
using namespace std;  
const int MaxN = 110;  
  
int R, C;  
int H[MaxN][MaxN];                           //  记录图各点的高度  
int L[MaxN][MaxN];                            //  记录以各点为起点的最长下降路径的长度  
  
int search(int i,int j){            //记忆化搜索
    if (L[i][j])
        return L[i][j];
    int maxL=1;
    if (i>=2 && H[i][j]>H[i-1][j])
        maxL=max(maxL,search(i-1,j)+1);

    if (j>=2 && H[i][j]>H[i][j-1])
        maxL=max(maxL,search(i,j-1)+1);

    if (i<=R-1 && H[i][j]>H[i+1][j])
        maxL=max(maxL,search(i+1,j)+1);

    if (j<=C-1 && H[i][j]>H[i][j+1])
        maxL=max(maxL,search(i,j+1)+1);
    
    L[i][j]=maxL;
    return maxL;
}

int main()  
{  
    cin>>R>>C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin>>H[i][j];
    memset(L,0,sizeof(L));
    int ans=0;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
        {
            int len=search(i,j);
            ans=max(ans,len);
        }
    cout<<ans<<endl;
    return 0;  
}  